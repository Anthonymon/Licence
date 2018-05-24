<html><head><title>Birthdays Create Database</title></head>
<body>
<?php
$link = new mysqli("localhost","in311","password");//user=in311, password=password
if ($link->connect_errno){
  die("Couldn't connect to MySQL ".$link->connect_error);
}
//create database
$db = "birthdaytest1";
$q = "CREATE DATABASE " . $db;
if (!$link->query($q)){
  die("Create Error: ".$link->error);
}
echo "Database ". $db . " created !";
$link->close();
?> 
</body>
</html>
