<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Stats Modification
		</title>
	</head>
	
	<body> 		
		<?php
			include("bordereau.php");
		?>
			
		<p>
			<?php
				// on recherche les informations du joueur ainsi que ses statistiques
				$nomJoueur=$_POST['nomJoueur'];
				$requete="SELECT prenom_joueur,age,identificateur_stats FROM joueur WHERE joueur.nom_joueur=\"$nomJoueur\"";
				$reponse1 = $link->query($requete) or die("Error SQL Select joueur: " .$link->error);
				if($donnees = $reponse1->fetch_assoc()){
					$prenomJoueur=$donnees['prenom_joueur'];
					$ageJoueur=$donnees['age'];
					$id=$donnees['identificateur_stats'];
					$requeteStats="SELECT * FROM stats WHERE stats.identificateur_stats=\"$id\"";
					$reponse2 = $link->query($requeteStats) or die("Error SQL Select stats: ".$link->error);
					
					$AB;$AVG;$HR;$RBI;$SB;$OPS;
					if($donneesStats=$reponse2->fetch_assoc()){
						$AB=$donneesStats['AB'];
						$AVG=$donneesStats['AVG_stats'];
						$HR=$donneesStats['HR'];
						$RBI=$donneesStats['RBI'];
						$SB=$donneesStats['SB'];
						$OPS=$donneesStats['OPS'];
					}
					?>
					<!-- Formulaire pour modifier les stats d'un joueur -->
					<form method="POST" action="validation_modif_stats.php">
						<input type="hidden" name="username" value="<?php print $_POST['username']?>">
						<input type="hidden" name="password" value="<?php print $_POST['password']?>">
						<input type="hidden" name="ancienNomEntraineur" value="<?php print $nomEntraineur?>"> <!-- inutile -->
						<input type="hidden" name="ancienPrenomEntraineur" value="<?php print $prenomEntraineur?>"> <!-- inutile -->
						<input type="hidden" name="identifiant" value="<?php print $id?>"> 
						<?php $photo="img/joueurs/".str_replace(" ","_",$_POST['ville'])."/".$id.".jpg"; ?>
						<img class="player" src=<?php printf("$photo") ?>>
						<br><br><br>
						Last Name : 
						<input type="text" name="nomJoueur" value="<?php printf($nomJoueur)?>" required>
						&nbsp;&nbsp;&nbsp; First Name :
						<input type="text" name="prenomJoueur" value="<?php printf($prenomJoueur)?>" required>
						<br><br><br>
					
						Age : 
						<input type="number" name="ageJoueur" value="<?php printf($ageJoueur)?>" min=18 required>
						&nbsp;&nbsp;&nbsp;
						<br><br><br>
						AB : 
						<input type="number" name="AB" value="<?php printf($AB)?>" min=0>
						&nbsp;&nbsp;
						AVG : 
						<input type="number" name="AVG" value="<?php printf($AVG)?>" min=0 max=1 step="0.001">
						&nbsp;&nbsp;
						HR : 
						<input type="number" name="HR" value="<?php printf($HR)?>" min=0>
						&nbsp;&nbsp;
						<br><br>
						RBI : 
						<input type="number" name="RBI" value="<?php printf($RBI)?>" min=0>
						&nbsp;&nbsp;
						SB : 
						<input type="number" name="SB" value="<?php printf($SB)?>" min=0>
						&nbsp;&nbsp;
						OPS :
						<input type="number" name="OPS" value="<?php printf($OPS)?>" min=0 max=2 step="0.001">
						<br><br><br><br>
						<?php
							$reponse2->free();
				} ?>
				<input value="Abandon" type="reset">
				<input value="Validation" type="submit">
			</form>
			
			<?php
				$reponse1->free();
				$link->close();
			?>
		</p>
	</body> 

</html> 
