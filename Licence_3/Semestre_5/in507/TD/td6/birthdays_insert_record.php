<html><head><title>Birthdays Insert Record</title></head>
<body>
<?php
$name=$_POST['name'];
$birthday=$_POST['birthday'];
$db="birthdaytest1";
//$link = mysql_connect("localhost","in311","test");
$link = new mysqli("localhost",$_POST['username'],$_POST['password']);
if ($link->connect_errno){
  die("Couldn't connect to MySQL ".$link->connect_error);
}
$link->select_db($db) or die("Select Error: ".$link->error);
$result=$link->query("INSERT INTO birthdays (name, birthday) VALUES ('$name','$birthday')")or die("Insert Error: ".$link->error());
$link->close();
print "Record added\n";
?>
<form method="POST" action="birthdays_insert_form.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Insert Another Record">
</form>
</body>
</html>
