<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Team Modification
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
			
		<p>
			<?php
				// on recherche les informations de l'equipe a modifier
				$cityTeam=$_POST['equipe'];
				$requete="SELECT * FROM equipe WHERE equipe.ville=\"$cityTeam\"";
				$reponse1 = $link->query($requete)or die("Error SQL Select equipe: ".$link->error);
				if($donnees = $reponse1->fetch_assoc()){ 
					$nomTeam=$donnees['nom'];
					$nomEntraineur=$donnees['nom_entraineur'];
					$prenomEntraineur=$donnees['prenom_entraineur'];
					?>
					<!-- Modification d'une equipe avec le nom de l'entraineur et le nom/ville de l'équipe -->
					<form method="POST" action="validation_modif_team.php">
						<input type="hidden" name="username" value="<?php print $_POST['username']?>">
						<input type="hidden" name="password" value="<?php print $_POST['password']?>">
						<input type="hidden" name="ancienNomEntraineur" value="<?php print $nomEntraineur?>">
						<input type="hidden" name="ancienPrenomEntraineur" value="<?php print $prenomEntraineur?>">
						<input type="hidden" name="ancienNomVille" value="<?php print $_POST['equipe']?>">
						<?php $photo="img/equipes/".str_replace(" ","_",$_POST['equipe']).".png"; ?>
						<img class="modifEquipe" src=<?php printf("$photo")?>>
						
						City : 
						<input type="text" name="villeEquipe" value="<?php printf($cityTeam)?>" required>
						&nbsp;&nbsp;&nbsp; Name :
						<input type="text" name="nomEquipe" value="<?php printf($nomTeam)?>" required>
						<br><br><br>
					
						Last Name of the Coach : 
						<input type="text" name="nomEntraineur" value="<?php printf($nomEntraineur)?>" required>
						&nbsp;&nbsp;&nbsp;
						<br><br>
						First Name of the Coach : 
						<input type="text" name="prenomEntraineur" value="<?php printf($prenomEntraineur)?>" required>
						<br><br>
						<br><br>
						<?php 
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
