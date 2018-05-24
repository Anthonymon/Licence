<html><head><title></title></head>
<body>
<?php
$id=$_POST['id'];
$db="birthdaytest1";
$link = new mysqli("localhost",$_POST['username'],$_POST['password']);
//$link = mysql_connect("localhost", "in311", "password");
if ($link->connect_errno){
  die("Couldn't connect to MySQL ".$link->connect_error);
}

$link->select_db($db)
or die("Couldn't open $db: ".$link->error);

$query=" SELECT * FROM birthdays WHERE id='$id'";
$result=$link->query($query);
$num=$result->num_rows;

$i=0;
while ($i < $num) {
  $result->data_seek($i);
  $row=$result->fetch_assoc();
  $name=$row["name"];
  $birthday=$row["birthday"];
?>
<table width="300" cellpadding="10" cellspacing="0" border="2">
<tr align="center" valign="top">
<td align="center" colspan="1" rowspan="1" bgcolor="#64b1ff">
<h3>Edit and Submit</h3>
<form action="birthdays_change_record.php" method="post">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="hidden" name="ud_id" value="<?php echo "$id" ?>">
Name:    <input type="text" name="ud_name" value="<?php print "$name"?>"><br>
Birthday:    <input type="text" name="ud_birthday" value="<?php echo "$birthday"?>"><br>
<input type="Submit" value="Update">
</form>
</td></tr></table>

<?php
++$i;
}
?>
</body>
</html>
