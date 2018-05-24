<html><head><title></title></head>
<body>
<table width="300" cellpadding="10" cellspacing="0" border="2">
<tr align="center" valign="top">
<td align="left" colspan="1" rowspan="1" bgcolor="64b1ff">
<h3>Birthdays Interface</h3>
<form method="POST" action="birthdays_insert_form.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Insert Record">
</form><br>
<form method="POST" action="birthdays_display_records.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Display Records">
</form><br>
<form method="POST" action="birthdays_update_form.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Update Records">
</form><br>
<form method="POST" action="birthdays_delete_form.php">
<input type="hidden" name="username" value="<?php print $_POST['username']?>">
<input type="hidden" name="password" value="<?php print $_POST['password']?>">
<input type="submit" value="Delete Record">
</form><br>
</td></tr></table>
</body>
</html>
