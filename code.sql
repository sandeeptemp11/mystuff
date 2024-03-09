-- Inserting data using create_user function
select create_user('_sandeep__', 'sandeep reddy', '112101011@smail.iitpkd.ac.in', 'palakkad@3');
select create_user('_manish_', 'manish', '112101002@smail.iitpkd.ac.in', 'apple@22');
select create_user('swarna_bai', 'sunapral swarnalatha bai', '112101003@smail.iitpkd.ac.in', 'pass123');
select create_user('_sandeep__', 'sandy', 'sandeep@gmail.com', 'iitpkd@2025');
select create_user('_ram__', 'ram', 'ram@iitpkd.ac.in', 'ram@2024');
select * from developer;

-- dropping a user (deleting an account in octopus)
select drop_user('_ram__');
select * from developer;

-- creating a new repo (data)
select from create_repo('lab1', '_sandeep__');
select from create_repo('lab1', '_manish_');
-- invalid user name
select from create_repo('lab3', 'andeep__');
select from create_repo('lab3', 'swarna_bai');
select * from repositry;


-- granting collaboration
call grant_collab_access('lab1', '_sandeep__', 'swarna_bai');
select * from collaborate;
select * from repositry;

select * from 

select from create_repo('lab2', '_sandeep__');
select from create_repo('lab3', '_sandeep__');
select from create_repo('lab4', '_manish_');
select from create_repo('lab5', '_sandeep__');

select * from repositry;
-- Query1) Given a repository find the details of owner.
SELECT developer.developer_id, developer.name
FROM developer join repositry on (developer.developer_id = repositry.owner_id and repositry.repositry_name = 'lab1');

-- Query2) Find all repostories owned by '_manish_'
SELECT repositry.*
FROM developer join repositry on (developer.user_name = '_manish_' and developer.developer_id = repositry.owner_id)
;

-- Query2) Find all repostories owned by '_manish_'
SELECT repositry.*
FROM developer join repositry on (developer.user_name = '_manish_' and developer.developer_id = repositry.owner_id)
;

select * from collaborate;
-- Query3) Find the name of collaborator of repository with repository_id = 1
SELECT developer.developer_id, developer.name
FROM collaborate join developer on (collaborate.repositry_id = 1 and developer.developer_id = collaborate.developer_id);

-- Query4) Given a repository(id 1) find all users who have edit access (that is all people who can contribute: owner + colaborator)
(SELECT developer.developer_id, developer.name
FROM developer join repositry on (developer.developer_id = repositry.owner_id and repositry.repositry_id = 1) )
union
(SELECT developer.developer_id, developer.name
FROM collaborate join developer on (collaborate.repositry_id = 1 and developer.developer_id = collaborate.developer_id));

-- Query5) Print the content of a file present in repository with repository_id = 1
SELECT file.content
FROM repositry join file on repositry.repositry_id = file.parent_repositry_id
WHERE repositry.repositry_id = 1;


-- DATABASE DESIGN 

DROP EXTENSION IF EXISTS pgcrypto;
drop table if exists sub_repositry CASCADE;
DROP TABLE IF EXISTS commit CASCADE;
DROP TABLE IF EXISTS tag CASCADE;
DROP TABLE IF EXISTS file CASCADE;
DROP TABLE IF EXISTS comment CASCADE;
DROP TABLE IF EXISTS collaborate CASCADE;
DROP TABLE IF EXISTS access CASCADE;
DROP TABLE IF EXISTS fork CASCADE;
drop table if exists repositry CASCADE;
drop table if exists developer CASCADE;

-- Developer table
CREATE EXTENSION IF NOT EXISTS pgcrypto;
create table developer(
	developer_id SERIAL PRIMARY KEY,
	user_name VARCHAR(100) UNIQUE NOT NULL,
	name VARCHAR(100) NOT NULL,
	email VARCHAR(100) UNIQUE NOT NULL,
	encrypted_password VARCHAR(100) NOT NULL,
	num_repos INT DEFAULT 0,
	storage_used INT DEFAULT 0,
	total_commits INT DEFAULT 0
);

-- The function check_user (lookup)
-- 					returns true if the input user_name is present (that is the provided user_name is valid)
-- 					returns false otherwise 
DROP FUNCTION IF EXISTS check_user;
CREATE OR REPLACE FUNCTION check_user(user_name VARCHAR(100))
RETURNS BOOLEAN
as $$
BEGIN
	RETURN check_user.user_name IN (SELECT developer.user_name FROM developer WHERE developer.user_name = check_user.user_name);
END;
$$ LANGUAGE plpgsql;


-- function create_user
-- 					creates user if email, username are not already found in developer table and returns true if valid,
-- 					else return false
drop function if exists create_user;
CREATE  OR REPLACE FUNCTION create_user(user_name VARCHAR(100), name VARCHAR(100), email VARCHAR(100), pass VARCHAR(100))
RETURNS BOOLEAN
as $$
BEGIN
	if (create_user.user_name in (select developer.user_name from developer)) then
		RAISE NOTICE '% user_name already exists!!', create_user.user_name;
		if (create_user.email in (select developer.email from developer)) then
			RAISE NOTICE '% is already linked to an account!!', create_user.email;
		end if;
		return false;
	end if;
	if (create_user.email in (select developer.email from developer)) then
		RAISE NOTICE '% is already linked to an account!!', create_user.email;
		return false;
	end if;
	INSERT INTO developer(user_name, encrypted_password, name, email) 
	VALUES (create_user.user_name, (crypt(create_user.pass, gen_salt('bf'))) , create_user.name, create_user.email);
	RAISE NOTICE 'Welcome to cloud-repositry octopus %!!', create_user.name;
	return true;
END;
$$ LANGUAGE plpgsql;

-- function drop_user
-- 			returns true and deletes the tuple corresponding to user_name if user_name is present in developer_table
-- 			returns false otherwise
drop function if exists drop_user;
CREATE  OR REPLACE FUNCTION drop_user(user_name VARCHAR(100))
RETURNS BOOLEAN
as $$
BEGIN
	if (drop_user.user_name in (select developer.user_name from developer)) then
		DELETE FROM developer
		WHERE developer.user_name = drop_user.user_name;
		RAISE NOTICE '% is deleted!!', drop_user.user_name;
		return true;
	end if;
	RAISE NOTICE '% user_name does not exist!!', drop_user.user_name;
	return false;
END;
$$ LANGUAGE plpgsql;
 
-- 2) repositry table
create table repositry(
	repositry_id SERIAL PRIMARY KEY,
	repositry_name VARCHAR(100) NOT NULL,
	size INT DEFAULT 0,
	created_date_time timestamp,
	last_update timestamp,
	owner_id INT NOT NULL,
	is_public BOOLEAN DEFAULT true,
	num_workers INT DEFAULT 1,
	FOREIGN KEY (owner_id) REFERENCES developer(developer_id)
);

-- 3) sub_repositry table
create table sub_repositry(
	parent_repo_id INT NOT NULL,
	child_repo_id INT PRIMARY KEY,
	
	FOREIGN KEY(parent_repo_id) REFERENCES repositry(repositry_id),
	FOREIGN KEY(child_repo_id) REFERENCES repositry(repositry_id)
);

-- function create_repo
drop function if exists create_repo;
CREATE  OR REPLACE FUNCTION create_repo(repositry_name VARCHAR(100), user_name VARCHAR(100))
RETURNS BOOLEAN
as $$
BEGIN
	/* for a user, a repo name is unique */
	if (create_repo.repositry_name in  (select repositry.repositry_name
										from repositry, developer
										where repositry.owner_id = developer.developer_id and developer.user_name = create_repo.user_name)) then
		/* repositry is already present in repos of owner*/
		RAISE NOTICE '% already exists in % repostires', create_repo.repositry_name, create_repo.user_name;
		return false;
	end if;
	
	if(check_user(user_name) = false) then
		RAISE NOTICE '% user_name is invalid!!', create_repo.user_name;
		RETURN false;
	end if;
	
	/* Updating number of repositires of owner */
	UPDATE developer
	SET num_repos = num_repos + 1
	WHERE developer.user_name = create_repo.user_name;
	
	/* creating a new repositry */
	INSERT INTO repositry(repositry_name, created_date_time, last_update, owner_id)
	VALUES ( create_repo.repositry_name,
			 localtimestamp,
			 localtimestamp,
			 (select developer.developer_id
			 from developer
		     where developer.user_name = create_repo.user_name)
	);
	
	RAISE NOTICE '% created!!', create_repo.repositry_name;
	return true;
END;
$$ LANGUAGE plpgsql;

-- 4) collaborate
CREATE TABLE collaborate(
	repositry_id INT,
	developer_id INT,
	FOREIGN KEY (repositry_id) REFERENCES repositry(repositry_id) ON DELETE CASCADE,
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id) ON DELETE CASCADE,
	PRIMARY KEY (repositry_id, developer_id)
);

-- procedure grant_collab_access
-- 			will grant acess if inputs are valid (owner grants collboration access to another user)
-- NOTE: A owner by default edit, read access to repositry. 
-- In this design, collaborator is one who has edit and read access of repositry.(which genrally is the case)
drop procedure if exists grant_collab_access;
CREATE OR REPLACE PROCEDURE grant_collab_access(repositry_name VARCHAR(100), owner_user_name VARCHAR(100), to_user_name VARCHAR(100))	
AS $$
DECLARE 
dont_grant boolean DEFAULT false;
BEGIN
	/* checking for validity of user_names */
	IF (check_user(owner_user_name) = false) THEN
		RAISE NOTICE '% is not present', owner_user_name;
		dont_grant := true;
	END IF;
	IF (check_user(to_user_name) = false) THEN
		RAISE NOTICE '% is not present', owner_user_name;
		dont_grant := true;
	END IF;
	
	IF (dont_grant = false) AND (grant_collab_access.repositry_name not in  
								(SELECT repositry.repositry_name FROM repositry join developer on repositry.owner_id = developer.developer_id
			    				 WHERE  repositry.owner_id = developer.developer_id AND developer.user_name = grant_collab_access.owner_user_name)) THEN
		RAISE NOTICE '% is not owner of repositry %', owner_user_name, repositry_name;
		dont_grant := true;
	END IF;
	
	IF (dont_grant = false) THEN
		/* grant access */
		INSERT INTO collaborate
		VALUES  ((select repositry.repositry_id
				  from repositry, developer
				  where repositry.owner_id = developer.developer_id and developer.user_name = grant_collab_access.owner_user_name and repositry.repositry_name = grant_collab_access.repositry_name),
				 (select developer.developer_id
				  from  developer
				  where developer.user_name = grant_collab_access.to_user_name));
				  
		/* modify repositry */
		UPDATE repositry
		SET num_workers = num_workers + 1
		WHERE repositry.repositry_id in (SELECT repositry.repositry_id FROM repositry, developer
										 WHERE repositry.repositry_name = grant_collab_access.repositry_name AND
									    	   repositry.owner_id = developer.developer_id AND
										  	   grant_collab_access.owner_user_name = developer.user_name);
		RAISE NOTICE 'Access granted!!';
	ELSE
		RAISE NOTICE 'Access denied!!';
	END IF;
END;
$$ LANGUAGE plpgsql;

-- TABLE access
DROP TABLE IF EXISTS access;
CREATE TABLE access(
	repositry_id INT,
	developer_id INT,
	FOREIGN KEY (repositry_id) REFERENCES repositry(repositry_id),
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id),
	PRIMARY KEY(repositry_id, developer_id)
);

-- procedure grant_access
-- 			will grant acess if inputs are valid (owner grants view access to another user iff the repositry is not public to view)
-- NOTE: owner and collaborator by default has read access to repositry. 
-- In this design, if a repositry is not public then the owner can grant view access to the selected developers.
drop procedure if exists grant_access;
CREATE OR REPLACE PROCEDURE grant_access(repositry_name VARCHAR(100), owner_user_name VARCHAR(100), to_user_name VARCHAR(100))	
AS $$
DECLARE 
dont_grant boolean DEFAULT false;
BEGIN
	/* checking for validity of user_names */
	IF (check_user(owner_user_name) = false) THEN
		RAISE NOTICE '% is not present', owner_user_name;
		dont_grant := true;
	END IF;
	IF (check_user(to_user_name) = false) THEN
		RAISE NOTICE '% is not present', owner_user_name;
		dont_grant := true;
	END IF;
	
	IF (dont_grant = false) AND (grant_access.repositry_name not in  
								(SELECT repositry.repositry_name FROM repositry join developer on repositry.owner_id = developer.developer_id
			    				 WHERE repositry.owner_id = developer.developer_id AND developer.user_name = grant_access.owner_user_name)) THEN
		RAISE NOTICE '% is not owner of the repositry %', owner_user_name, repositry_name;
		dont_grant := true;
	END IF;
	
	IF (dont_grant = true) THEN 
		RAISE NOTICE 'Access denied!!';
	END IF;
	
	IF (dont_grant = false) AND
	   (SELECT repositry.is_public FROM repositry JOIN developer ON repositry.owner_id = developer.developer_id
		WHERE repositry.repositry_name = grant_access.repositry_name AND
			  grant_access.owner_user_name = developer.user_name) THEN
		/* public repositry */
		RAISE NOTICE '% of % is public, % has access already!!', grant_access.repositry_name, grant_access.owner_user_name, grant_access.to_user_name;
		dont_grant = true;
	END IF;
	
	IF (dont_grant = false) THEN
		INSERT INTO access
		VALUES  ((SELECT repositry.repositry_id
				  FROM repositry, developer
				  WHERE repositry.owner_id = developer.developer_id AND
				  		developer.user_name = grant_access.owner_user_name AND
				  		repositry.repositry_name = grant_access.repositry_name),
				 (select developer.developer_id
				  from  developer
				  where developer.user_name = grant_access.to_user_name));
		RAISE NOTICE 'Access granted!!';
	END IF;
END;
$$ LANGUAGE plpgsql;

-- TABLE comment
DROP TABLE IF EXISTS comment;
CREATE TABLE comment(
	repositry_id INT,
	developer_id INT,
	comment_id SERIAL, 
	messgae	VARCHAR(100),
	comment_date_time timestamp,
	
	PRIMARY KEY(repositry_id, developer_id, comment_id),
	FOREIGN KEY (repositry_id) REFERENCES repositry(repositry_id),
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id)
);

-- procedure add_comment
--  		 adds comment to the comment_table provided if the given inputs repositry_id, user_name are valid
-- NOTE: 1) We cannot take only repositry_name as input parameter for adding comment because there could be multiple repositires with same repositry_name
-- 		 2) The current database design supports that any user of OCTOPUS can comment on a repositry, if the repositry is public (or) he is the owner of the repositry (or) collaborator of the repositry (or) has access (view basically) to the repositry.
-- 			(that is having at least view access)
DROP PROCEDURE IF EXISTS add_comment;
CREATE OR REPLACE PROCEDURE add_comment(repositry_id INT, user_name VARCHAR(100), message VARCHAR(100))
AS $$
DECLARE have_permission BOOLEAN DEFAULT false;
invoke_id INT;
BEGIN
	IF ((add_comment.repositry_id IN  (SELECT repositry.repositry_id FROM repositry)) AND
		(add_comment.user_name IN (SELECT developer.user_name FROM developer))) THEN
		-- given repositry_id and user_name are valid
		invoke_id = (select developer_id FROM developer WHERE developer.user_name = add_comment.user_name);
		
		IF ((select is_public FROM repositry WHERE repositry.repositry_id = add_comment.repositry_id) = true) then
			/* public repositry */
			have_permission := true;
		ELSIF ((select owner_id FROM repositry WHERE repositry.repositry_id = add_comment.repositry_id) = invoke_id) THEN
			/* is owner */
			have_permission := true;
		ELSIF ( invoke_id IN (SELECT collaborate.developer_id FROM collborate WHERE collaborate.repositry_id = add_comment.repositry_id)) THEN
			/* collaborator */
			have_permission := true;
		ELSIF (invoke_id IN (SELECT access.developer_id FROM access WHERE access.repositry_id = add_comment.repositry_id)) THEN
			/* private view access */
			have_permission := true;
		END IF;
		
		IF (have_permission) THEN
			INSERT INTO comment(repositry_id, developer_id, message, comment_date_time)
			VALUES (add_comment.repositry_id,
					invoke_id,
					add_comment.message,
					localtimestamp);
			RAISE NOTICE 'Comment added!!';			
		ELSE
			RAISE NOTICE 'From procedure add_comment: No access for % to comment repository with repository_id %!!', add_comment.user_name, add_comment.repository_id;
		END IF;
	ELSE
		RAISE NOTICE 'Invalid input!!';
	END IF;
END;
$$ LANGUAGE plpgsql;

-- TABLE file
drop table if exists file;
create table file(
	file_id	SERIAL PRIMARY KEY,
	file_name VARCHAR(50) NOT NULL,
	file_type VARCHAR(10),
	size INT DEFAULT 0,
	content text,
	parent_repositry_id INT NOT NULL,
	last_update timestamp,
	FOREIGN KEY(parent_repositry_id) REFERENCES repositry(repositry_id) ON DELETE CASCADE
);

INSERT INTO file
VALUES (1, 'dbms_project', '.txt', length('This is a mid-sem report'), 'This is a mid-sem report', 1, localtimestamp);
SELECT * FROM file;

-- TABLE commit
create table commit(
	commit_id INT,
	repositry_id INT,
	developer_id INT,
	message	VARCHAR(100),
	data_snap_shot	data,
	commit_date_time timestamp,
	PRIMARY KEY(commit_id, repositry_id, developer_id),
	FOREIGN KEY (repositry_id) REFERENCES repositry(repositry_id),
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id)
);

-- TABLE tag
drop table if exists tag;
create table tag(
	repositry_id INT,
	developer_id INT,
	tag_id INT,
	commit_id INT,
	tag_name VARCHAR(50) UNIQUE NOT NULL,
	tag_date_time timestamp,
	
	PRIMARY KEY(repositry_id, developer_id, tag_id),
	FOREIGN KEY (repositry_id) REFERENCES repositry(repositry_id),
	FOREIGN KEY (developer_id) REFERENCES developer(developer_id),
	FOREIGN KEY (commit_id) REFERENCES commit(commit_id)
);


-- we are currently making owner,collabarator, the one who have access as sepearete to avoid redundancies
-- for maintaining commits and tags, one possible way is that there is admin user who maintains all these copies. (good idea)
