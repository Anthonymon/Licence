<html><head><title>Birthdays Delete Record</title></head>
<body>
<?php
$user=$_POST['username'];
$password=$_POST['password'];
$id=$_POST['id'];
$db="birthdaytest1";
$link = new mysqli("localhost",$user,$password);
if ($link->connect_errno){
 die("Couldn't connect to MySQL ".$link->connect_error);
}
$link->select_db($db)
or die("Couldn't open $db: ".$link->error);
$link->query("DELETE FROM  birthdays where id=$id")or die("Delete Error: ".$link->error);
$link->close();
print "Record Removed.\n";
?>
<br><br>
<form method="POST" action="birthdays_delete_form.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Delete Another">
</form><br>
<form method="POST" action="birthdays_dbase_interface.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="DBase Interface">
</form>
</body>
</html>
