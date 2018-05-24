<?php
ini_set('display_errors','off');
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Menu
		</title>
	</head>

	<body> 
		<p class="bordure" >
		<img class="logo" src="img/autres/menu_logo.jpg">
			
	<?php // connexion a la base de donnees avec username et password
		$username="visiteurbaseball";
		$password="visiteur";
		$link = new mysqli('localhost', $username, $password);
		if ($link->connect_errno) {
			printf("</p>");
			die ("Authentication failed");
		}
		$link->select_db('user') or die("Erreur selection BD: " . $link->error);
		
	?> 
	
	<!-- Creation du bouton pour voir les statistiques -->
	<form method="POST" action="stats.php">
		<input type="hidden" name="username" value="<?php print $username?>">
		<input type="hidden" name="password" value="<?php print $password?>">
		<input class="boutonStats" type="image" name="boutonStats" src="img/autres/bouton_stats.png"> 
	</form>
	
	<!-- Creation du bouton pour voir les scores (et l'arbre) -->
	<form method="POST" action="scores.php">
		<input type="hidden" name="username" value="<?php print $username?>">
		<input type="hidden" name="password" value="<?php print $password?>">
		<input class="boutonScores" type="image" name="boutonScores" src="img/autres/bouton_scores.png"> 
	</form>
	
	<!-- Creation du bouton pour voir les équipes -->
	<form method="POST" action="teams.php">
		<input type="hidden" name="username" value="<?php print $username?>">
		<input type="hidden" name="password" value="<?php print $password?>">
		<input class="boutonTeams" type="image" name="boutonTeams" src="img/autres/bouton_teams.png"> 
	</form>
	
	<!-- Creation du bouton pour se déconnecter -->
	<form method="POST" action="connexion.php">
		<input type="hidden" name="username" value="<?php print $username?>">
		<input type="hidden" name="password" value="<?php print $password?>">
		<input class="boutonQuitter" type="image" name="boutonQuitter" src="img/autres/bouton_profil.png"> 
	</form>
		
		<img class="gifPresentation" src="img/autres/index.gif" >
		<br><br>
		<?php
			$link->close();
		?>
	</body> 

</html> 
