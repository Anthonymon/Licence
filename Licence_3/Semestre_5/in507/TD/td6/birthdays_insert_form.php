<html><head><title>Birthdays Insert Form</title></head>
<body>
<table width="300" cellpadding="5" cellspacing="0" border="2">
<tr align="center" valign="top">
<td align="left" colspan="1" rowspan="1" bgcolor="64b1ff">
<h3>Insert Record</h3>
<form method="POST" action="birthdays_insert_record.php">
<!--The hidden fields are provided to maintain state.  They are used to pass the username and password from script to script.-->
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<?php
print "Enter name: <input type=text name=name size=20><br>\n";
print "Enter Birthday: <input type=text name=birthday size=10><br>\n";
print "<br>\n";
print "<input type=submit value=Submit><input type=reset>\n";
?>
</form>
</td></tr></table>
</body>
</html>
