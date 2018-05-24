<html><head><title>Birthdays Update Form</title></head>
<body>
<?php
$username=$_POST['username'];
$password=$_POST['password'];
$db="birthdaytest1";
$link = new mysqli("localhost", $username, $password);
if ($link->connect_errno){
  die("Couldn't connect to MySQL ".$link->connect_error);
}
$link->select_db($db)
or die("Couldn't open $db: ".$link->error);
$result = $link->query( "SELECT * FROM birthdays" )
or die("SELECT Error: ".$link->error);
$num_rows = $result->num_rows;
print "There are $num_rows records.<P>";
print "<table width=200 border=1>\n";
while ($get_info = $result->fetch_row()){ 
print "<tr>\n";
foreach ($get_info as $field) 
print "\t<td><font face=arial size=1/>$field</font></td>\n";
print "</tr>\n";
}
print "</table>\n";
$result->free();
$link->close();
?>
<br>
<form method="POST" action="birthdays_change_form.php">
<pre>
Enter Line Number to Edit: <input type="text" name="id" size="5">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Submit"><input type="reset">
</pre>
</form>
</body>
</html>
