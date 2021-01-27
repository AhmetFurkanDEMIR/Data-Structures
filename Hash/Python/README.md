# Hash

Registered users or newly added users are kept in a file named veri.csv. In this .csv file, the user's password is hashed and stored with SHA-256. 
Example: a password whose hash has been taken = "86ea77f900598bec12fe13132944bc4587b5ad70f5c28809897ab2f970aac898" It is not possible to return to the password
from this saved hash. It hash the password given as input and compares it, if the passwords are the same, it logs in.

