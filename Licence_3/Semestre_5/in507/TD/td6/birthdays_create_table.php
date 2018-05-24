<html><head><title>Birthdays Create Table</title></head>
<body>
<?php
$db="birthdaytest1";
$link = new mysqli("localhost","in311","password");
if ($link->connect_errno){
  die("Couldn't connect to MySQL ".$link->connect_error);
}
$link->select_db($db)
or die("Select DB Error: ".$link->error);
//create table
$link->query("CREATE TABLE birthdays( id INT NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), name VARCHAR(30), birthday VARCHAR(7))") 
or die("Create table Error: ".$link->error);
echo "Table créée !";
$link->close();

?>
</body>
</html>

