<?php
ini_set('display_errors','off');
?>

<?php
	//fonction qui supprime l'entraineur si l'equipe ne peut pas etre cree 
	function problemeInsertTeam($error,$link,$nomEntraineur,$prenomEntraineur){
		printf($error);
		echo "<br>";
		$requeteSupprCoach="DELETE FROM entraineur WHERE entraineur.nom_entraineur=\"$nomEntraineur\" AND entraineur.prenom_entraineur=\"$prenomEntraineur\"";
		$link->query($requeteSupprCoach)or die("Delete Error: ".$link->error);
		die("Can not insert this team");
	}
	
	//fonction qui supprime l'entraineur,les stats si l'equipe ne peut pas etre cree 
	function problemeInsertStat($error,$link,$ville,$nomEntraineur,$prenomEntraineur){
		printf($error);
		echo "<br>";
		
		//suppression du coach
		$requeteSupprCoach="DELETE FROM entraineur WHERE entraineur.nom_entraineur=\"$nomEntraineur\" AND entraineur.prenom_entraineur=\"$prenomEntraineur\"";
		$link->query($requeteSupprCoach)or die("Delete Error Entraineur: ".$link->error);
		
		//suppression des stats
		$requete="SELECT stats.identificateur_stats FROM stats";
		$reponseSelectJoueur=$link->query($requete)or die("Error SQL Select joueur: ". $link->error);
		$idComplet;
		while($donnees = $reponseSelectJoueur->fetch_assoc()){ 
			$id=$donnees['identificateur_stats'];
			if(($id[0]==$ville[0])&&($id[1]==$ville[1])){
				$requeteDeleteStats="DELETE FROM stats WHERE stats.identificateur_stats=\"$id\"";
				$link->query($requeteDeleteStats)or die("Delete Error: ".$link->error);
			}
		}
		$reponseSelectJoueur->free();
		die("Can not insert this team");
	}
	
	//fonction qui supprime l'entraineur,les stats et les joueurs si l'equipe ne peut pas etre cree 
	function problemeInsertPlayer($error,$link,$ville,$nomEntraineur,$prenomEntraineur){
		printf($error);
		echo "<br>";
		
		//suppression du coach
		$requeteSupprCoach="DELETE FROM entraineur WHERE entraineur.nom_entraineur=\"$nomEntraineur\" AND entraineur.prenom_entraineur=\"$prenomEntraineur\"";
		$link->query($requeteSupprCoach)or die("Delete Error Entraineur: ".$link->error);
		
		//suppression des stats
		$requete="SELECT stats.identificateur_stats FROM stats";
		$reponseSelectJoueur=$link->query($requete)or die("Error SQL Select joueur: ". $link->error);
		$idComplet;
		while($donnees = $reponseSelectJoueur->fetch_assoc()){ 
			$id=$donnees['identificateur_stats'];
			if(($id[0]==$ville[0])&&($id[1]==$ville[1])){
				$requeteDeleteStats="DELETE FROM stats WHERE stats.identificateur_stats=\"$id\"";
				$link->query($requeteDeleteStats)or die("Delete Error: ".$link->error);
			}
		}
		$reponseSelectJoueur->free();
		
		$requeteSupprPlayer="DELETE FROM joueur WHERE joueur.ville=\"$ville\"";
		$link->query($requeteSupprPlayer)or die("Delete Error Entraineur: ".$link->error);
		
		die("Can not insert this team");
	}

	// fonction pour inserer un joueur en fonction de son poste
	function insererJoueur($reponse1,$link,$compteur,$ville,$nom,$prenom,$age,$num,$AB,$AVG,$HR,$RBI,$SB,$OPS,$nomEntraineur,$prenomEntraineur){
		$poste;
		switch ($compteur) {
			case 1:
				$poste="P";
				break;
			case 2:
				$poste="C";
				break;
			case 3:
				$poste="1B";
				break;
			case 4:
				$poste="2B";
				break;
			case 5:
				$poste="3B";
				break;
			case 6:
				$poste="SS";
				break;
			case 7:
				$poste="LF";
				break;
			case 8:
				$poste="CF";
				break;
			case 9:
				$poste="RF";
				break;
		}
		$id=$ville[0].$ville[1].$num;
		$requete="INSERT INTO stats VALUES (\"$id\", \"$AB\", \"$AVG\",\"$HR\", \"$RBI\",\"$SB\",\"$OPS\")";
		$reponse1 = $link->query($requete)or problemeInsertStat("Error Insert Stats: ".$link->error,$link,$ville,$nomEntraineur,$prenomEntraineur);
		$requete="INSERT INTO joueur VALUES (\"$nom\", \"$prenom\", \"$num\",\"$poste\", \"$age\",\"$id\",\"$ville\")";
		$reponse1 = $link->query($requete)or problemeInsertPlayer("Error Insert Stats: ".$link->error,$link,$ville,$nomEntraineur,$prenomEntraineur);
	}
	
	
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Team Creation
		</title>
	</head>
	<body> 
			<?php
			include("bordereau.php");
			?>
			
			<p>
			<?php
				$ville=$_POST['ville'];
				$nomVille=$_POST['nomVille'];
				$league=$_POST['league'];
				$nomEntraineur=$_POST['nomCoach'];
				$prenomEntraineur=$_POST['prenomCoach'];
				$anneesCarriere=$_POST['anneesCarriere'];
				$nom;$prenom;$age;$num;$AB;$AVG;$HR;$RBI;$SB;$OPS;
				
				// creation de l'entraineur
				$requete="INSERT INTO entraineur VALUES (\"$nomEntraineur\", \"$prenomEntraineur\", $anneesCarriere)";
				$reponse1 = $link->query($requete)or die("Error Insert Coach: ". $link->error);
				
				// creation de l'equipe 
				$requete="INSERT INTO equipe VALUES (\"$ville\", \"$nomVille\", \"$league\",\"$nomEntraineur\", \"$prenomEntraineur\")";
				//$reponse1 = $link->query($requete)or die("Error Insert Team: ". $link->error);
				$reponse1 = $link->query($requete)or problemeInsertTeam("Error Insert Coach: ". $link->error,$link,$nomEntraineur,$prenomEntraineur);
				
				// creation des joueurs de l'equipe
				$compteur=1;
				while($compteur<10){
					$nom=$_POST["nom".$compteur];
					$prenom=$_POST["prenom".$compteur];
					$age=$_POST["age".$compteur];
					$num=$_POST["num".$compteur];
					$AB=$_POST["AB".$compteur];
					$AVG=$_POST["AVG".$compteur];
					$HR=$_POST["HR".$compteur];
					$RBI=$_POST["RBI".$compteur];
					$SB=$_POST["SB".$compteur];
					$OPS=$_POST["OPS".$compteur];
					insererJoueur($reponse1,$link,$compteur,$ville,$nom,$prenom,$age,$num,$AB,$AVG,$HR,$RBI,$SB,$OPS,$nomEntraineur,$prenomEntraineur);
					$compteur=$compteur+1;
				}
				printf("New Team, new Coach and new Players Inserted "."<br><br>");
				$reponse1->free();
				$link->close();
			?>
			</p>
			
	</body> 

</html> 
