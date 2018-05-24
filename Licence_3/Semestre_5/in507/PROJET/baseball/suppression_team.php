<?php
	ini_set('display_errors','off');
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Team Delete
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
		<p>
		<?php
			// on recherche les infos du coach car il sera supprime avec son equipe
			$cityTeam=$_POST['equipe'];
			$id;
			$requete="SELECT entraineur.nom_entraineur,entraineur.prenom_entraineur FROM equipe,entraineur WHERE entraineur.nom_entraineur=equipe.nom_entraineur AND entraineur.nom_entraineur=equipe.nom_entraineur AND equipe.ville=\"$cityTeam\"";
			$reponse1=$link->query($requete) or die("Error SQL Select equipe,entraineur: ". $link->error);
			if($donnees = $reponse1->fetch_assoc()){ 
				$nomEntraineur=$donnees['nom_entraineur'];
				$prenomEntraineur=$donnees['prenom_entraineur'];
			}
			// on recherche les infos des joueurs car ils seront tous supprimes avec leur equipe
			$requete="SELECT joueur.identificateur_stats FROM joueur WHERE joueur.ville=\"$cityTeam\"";
			$reponse2=$link->query($requete)or die("Error SQL Select joueur: ". $link->error);
			$idComplet;
			while($donnees = $reponse2->fetch_assoc()){ 
				$id=$donnees['identificateur_stats'];
				$idComplet=$id[0].$id[1];
				$requete3="DELETE FROM stats WHERE stats.identificateur_stats=\"$id\"";
				$link->query($requete3)or die("Delete Error: ".$link->error);
			}
			printf("Deleting Players Success. ");
			printf("<br>");
				
			$requete="DELETE FROM entraineur WHERE entraineur.nom_entraineur=\"$nomEntraineur\" AND entraineur.prenom_entraineur=\"$prenomEntraineur\"";
			$link->query($requete)or die("Delete Error: ".$link->error);
			printf("Deleting Coach Success. ");
			printf("<br>");
				
			$requete="DELETE FROM equipe WHERE equipe.ville=\"$cityTeam\"";
			$link->query($requete)or die("Delete Error: ".$link->error);
			printf("Deleting Team Success. ");
			
			$link->close();
			$reponse1->free();
			$reponse2->free();
		?>
		</p>
	</body> 

</html> 
