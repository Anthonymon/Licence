<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Player
		</title>
	</head>
	
	<body> 		
		<?php
			include("bordereau.php");
		?>
			
		<p>
			<?php
				// on recherche pour le joueur selectionne les informations de ce joueur avec ses statistiques
				$nomJoueur=$_POST['nomJoueur'];
				$ville=$_POST['ville'];
				$requete="SELECT prenom_joueur,age,identificateur_stats,ville,numero,poste FROM joueur WHERE joueur.nom_joueur=\"$nomJoueur\" AND joueur.ville=\"$ville\"";
				$reponse1 = $link->query($requete) or die("Error SQL Select joueur: ".$link->error);
				if($donnees = $reponse1->fetch_assoc()){
					$prenomJoueur=$donnees['prenom_joueur'];
					$ageJoueur=$donnees['age'];
					$id=$donnees['identificateur_stats'];
					$ville=$donnees['ville'];
					$numero=$donnees['numero'];
					$poste=$donnees['poste'];

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
				}
				$reponse1->free();
				$link->close();
				$photo="img/joueurs/".str_replace(" ","_",$ville)."/".$id.".jpg"; ?>
				<img class="player" src=<?php printf("$photo") ?> alt="Player">
				<br><br><br>
				<font size="4"><b>Last Name : </b></font>&nbsp;
				<?php printf($nomJoueur); ?>
				&nbsp;&nbsp;&nbsp; 
				<font size="4"><b>First Name : </b></font>
				<?php printf($prenomJoueur);?>
				&nbsp;&nbsp;&nbsp;
				<font size="4"><b>Age :  </b></font>
				<?php printf($ageJoueur);?>
				&nbsp;&nbsp;&nbsp;
				<font size="4"><b>Number :  </b></font>
				<?php printf($numero);?>
				&nbsp;&nbsp;&nbsp;
				<font size="4"><b>Position :  </b></font>
				<?php printf($poste);?>
				&nbsp;&nbsp;&nbsp;
				<br><br><br>
				<font size="4"><b>AB : </b></font>
				<?php printf($AB)?>
				&nbsp;&nbsp;
				<font size="4"><b>AVG : </b></font>
				<?php printf($AVG)?>
				&nbsp;&nbsp;
				<font size="4"><b>HR : </b></font>
				<?php printf($HR)?>
				&nbsp;&nbsp;
				<br><br>
				<font size="4"><b>RBI : </b></font>
				<?php printf($RBI)?>
				&nbsp;&nbsp;
				<font size="4"><b>SB : </b></font>
				<?php printf($SB)?>
				&nbsp;&nbsp;
				<font size="4"><b>OPS : </b></font>
				<?php printf($OPS)?>
		</p>
	</body> 

</html> 
