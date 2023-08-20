Create a sample file name 'sample.dat' in myexpos and write some data in it. <br/>

load the data into xfs-disk: <br/>
load --data $HOME/myexpos/sample.dat <br/>
We can observe the change at 69th location <br/>
<br/>

Now copy the root file content to some txt file <br/>
copy 5 5 $HOME/myexpos/rootcontent.txt <br/>

<br/>
The rootcontent.txt contains the following: <br/>
![image](https://github.com/sandeeptemp11/mystuff/assets/134224176/4694f368-e375-45a2-ae33-c76613498b58) <br/>

<br/>
**Assignment 2** <br/>
Delete the sample.dat file <br/>
rm sample.dat <br/>
copy 5 5 $HOME/myexpos/rootcontent.txt <br/>
 <br/>

After deleting the sample.dat file the changes are: <br/>
![image](https://github.com/sandeeptemp11/mystuff/assets/134224176/73826006-6120-4f80-ab9c-ae0c96f286ed) <br/>

In disk free list 69th location is free: <br/>
df <br/>
![image](https://github.com/sandeeptemp11/mystuff/assets/134224176/adfd3e8d-8b22-4462-a684-b7c4e1e07b39) <br/>

inode table after deleting: <br/>
dump --inodeusertable <br/>
![image](https://github.com/sandeeptemp11/mystuff/assets/134224176/5553857b-39d4-4d35-8e7f-ee5f4c12a921) <br/>
