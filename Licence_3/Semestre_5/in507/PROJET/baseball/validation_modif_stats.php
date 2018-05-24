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
				<!-- Mise a jour du joueur a modifier -->
				<?php
					$nom=$_POST['nomJoueur'];
					$prenom=$_POST['prenomJoueur'];
					$age=$_POST['ageJoueur'];
					$id=$_POST['identifiant'];
					$AB=$_POST['AB'];
					$AVG=$_POST['AVG'];
					$HR=$_POST['HR'];
					$RBI=$_POST['RBI'];
					$SB=$_POST['SB'];
					$OPS=$_POST['OPS'];

					$requete="UPDATE joueur SET nom_joueur=\"$nom\",prenom_joueur=\"$prenom\",age=\"$age\" WHERE joueur.identificateur_stats=\"$id\"";
					$link->query($requete)or die("Error Update Player: ". $link->error);
					$requete="UPDATE stats SET AB=\"$AB\",AVG_stats=\"$AVG\",HR=\"$HR\",RBI=\"$RBI\",SB=\"$SB\",OPS=\"$OPS\" WHERE stats.identificateur_stats=\"$id\"";
					$link->query($requete)or die("Error Update Stats: ". $link->error);
					$link->close();
					printf("Player Updated "."<br><br>");
				?>
			</p>
			
	</body> 

</html> 

