<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="connexion.css" type="text/css" > 
		<title>
			Connexion
		</title>
	</head>
	
	<body> 
		<br>
		<img class="logo" src="img/autres/logo.jpg"> <!-- Logo officiel du site -->
		
		<!-- Formulaire pour se connecter -->
		<form method="post" action="menu.php"> 
			<p class="FormulaireConnexion">Connexion <br><br><br>
			<input type="text" name="username" placeholder="Username" required><br><br>
			<input type="password" name="password" placeholder="Password" required><br><br><br><br>
			<input value="Abandon" type="reset">
			<input value="Validation" type="submit"></p>
		</form>
	</body> 

</html> 
