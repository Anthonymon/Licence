<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Matches Creation
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
			
		<!-- Formulaire pour creer un match  -->
		<form method="POST" action="validation_creation_match.php">
			<input type="hidden" name="username" value="<?php print $_POST['username']?>">
			<input type="hidden" name="password" value="<?php print $_POST['password']?>">
			<input type="hidden" name="team1" value="<?php print $_POST['equipe']?>">
			<p>
				<h2 class="titre">Matches Creation</h2> &nbsp;
				<br><br>
				<?php printf($_POST['equipe']); ?>
				&nbsp;&nbsp; - &nbsp;
				<select id="team2" name="team2"> <!-- on choisit la deuxieme equipe -->
					<?php 
						// on affiche toutes les equipes possibles 
						$compteur=1;
						$reponse1 = $link->query('SELECT * FROM equipe') or die("Error SQL Select equipe : ".$link->error);
						while ($donnees1 = $reponse1->fetch_assoc()){
							if($donnees1['ville']!=$_POST['equipe']){
							$myValue="\"".$donnees1['ville']."\"";
							?>
							<option value =<?php printf($myValue);?> required> <?php printf($donnees1['ville']);?></option>
							<?php
							$compteur=$compteur+1;
							}
						}
					?>
				</select><br><br><br>
		
				Type of matches : &nbsp;
				<select id="typeMatch" name="typeMatch"> <!-- on choisit le type de match -->
					<option value ="regularSeason" selected>Regular Season</option> 
					<option value ="playOffs">Play Offs</option>
				</select>
		 
				<br><br>

				First Match : &nbsp;
		
				<!-- on choisit les scores -->
				<input type="number" name="score_aller1" placeholder="Result Team 1" min=0 required>
				&nbsp; - &nbsp;
				<input type="number" name="score_aller2" placeholder="Result Team 2" min=0 required>
				&nbsp;
				<input type="text" name="date_aller" value="01/09/2017" required>
				<br><br>
		
				Second Match : &nbsp;
		
				<input type="number" name="score_retour2" placeholder="Result Team 2" min=0 required>
				&nbsp; - &nbsp;
				<input type="number" name="score_retour1" placeholder="Result Team 1" min=0 required>
				&nbsp;
				<input type="text" name="date_retour" value="01/09/2017" required>
				<br><br><br>
				<input value="Abandon" type="reset">
				<input value="Validation" type="submit">
			</p>
		</form>
		<?php 
			$link->close();
		?>
	</body> 
</html> 
