<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Match Modification
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
		<p>
			<?php
				// on recherche dans la bdd toutes les informations du match a modifier
				$id=$_POST['id'];
				$requete="SELECT * FROM matchs WHERE matchs.identificateur_match=\"$id\"";
				$reponse1 = $link->query($requete) or die("Error SQL Select matchs :".$link->error);
				if($donnees = $reponse1->fetch_assoc()){
					$date_match=$donnees['date_match'];
					$localMatch=$donnees['local_match'];
					$visiteurMatch=$donnees['visiteur_match'];
					$ptl=$donnees['ptl'];
					$ptv=$donnees['ptv'];
					?>
					<!-- Formulaire pour modifier le match selectionne-->
					<form method="POST" action="validation_modif_match.php">
						<input type="hidden" name="username" value="<?php print $_POST['username']?>">
						<input type="hidden" name="password" value="<?php print $_POST['password']?>">
						<input type="hidden" name="iden" value="<?php print $id?>">
						
						Match : &nbsp; <?php printf($date_match); ?><br><br>
					
						<?php printf($localMatch); ?> &nbsp;
						<input type="number" name="newPtl" value="<?php printf($ptl)?>" min=0>
						&nbsp; <?php printf(" - ");?> &nbsp;
						<input type="number" name="newPtv" value="<?php printf($ptv)?>" min=0>
						&nbsp;&nbsp;<?php printf($visiteurMatch); ?>
						<br><br><br>
					
						<input value="Abandon" type="reset">
						<input value="Validation" type="submit">
					</form>
					<?php 
				}
				
			$reponse1->free();
			$link->close();
		?>
		</p>
			
	</body> 

</html> 
