<?php
ini_set('display_errors','off');
?>

<?php
	
	function problemeInsertMatch($error,$link,$idMatch1){
		printf($error);
		echo "<br>";
		$requete="DELETE FROM matchs WHERE matchs.identificateur_match=\"$idMatch1\"";
		$link->query($requete)or die("Deleting Match Failed: ". $link->error);
		die("Can not insert these matches");
	}
	
	// fonction qui verifie si il ny a pas de matchs nuls 
	function verifierScores($ptl1,$ptv1,$ptl2,$ptv2){
		if($ptl1==$ptv1) die("Error : the First match is a draw ");
		if($ptl2==$ptv2) die("Error : the Second match is a draw ");
	}
		
	// fonction qui verifie si les dates des deux matchs ne sont pas identiques
	function verifierDates($date1,$date2){
		$boolDate1=1;
		$boolDate2=1;
		if(strlen($date1)!=10) $boolDate1=0;
		if(strlen($date2)!=10) $boolDate2=0;
		if(($date1[2]!='/')||($date1[5]!='/')) $boolDate1=0;
		if(($date2[2]!='/')||($date2[5]!='/')) $boolDate2=0;
		
		if(is_numeric($date1[0])!=true) $boolDate1=0; 
		if(is_numeric($date1[1])!=true) $boolDate1=0; 
		if(is_numeric($date1[3])!=true) $boolDate1=0; 
		if(is_numeric($date1[4])!=true) $boolDate1=0; 
		if(is_numeric($date1[6])!=true) $boolDate1=0; 
		if(is_numeric($date1[7])!=true) $boolDate1=0; 
		if(is_numeric($date1[8])!=true) $boolDate1=0; 
		if(is_numeric($date1[9])!=true) $boolDate1=0; 
		
		if(is_numeric($date2[0])!=true) $boolDate2=0; 
		if(is_numeric($date2[1])!=true) $boolDate2=0; 
		if(is_numeric($date2[3])!=true) $boolDate2=0; 
		if(is_numeric($date2[4])!=true) $boolDate2=0; 
		if(is_numeric($date2[6])!=true) $boolDate2=0; 
		if(is_numeric($date2[7])!=true) $boolDate2=0; 
		if(is_numeric($date2[8])!=true) $boolDate2=0; 
		if(is_numeric($date2[9])!=true) $boolDate2=0; 
		
		if($boolDate1==0) die("Error : the date of the First Match is invalid");
		if($boolDate2==0) die("Error : the date of the Second Match is invalid");

		if (strcasecmp($date1, $date2) == 0) {
			die("Error : Players can not play 2 matches during 24H");
		}
	}

	// verifier si en fonction du type de match les deux equipes peuvent s'affronter
	function verifierAdversaires($link,$team1,$team2,$typeMatch){
		$league1;$league2;
		$reponse1=$link->query("SELECT equipe.league FROM equipe WHERE equipe.ville=\"$team1\"") or die("Error SQL Select equipe: ". $link->error);
		if($donnees = $reponse1->fetch_assoc()){
			$league1=$donnees['league'];
		}
		$reponse2=$link->query("SELECT equipe.league FROM equipe WHERE equipe.ville=\"$team2\"") or die("Error SQL Select equipe: ". $link->error);
		if($donnees = $reponse2->fetch_assoc()){
			$league2=$donnees['league'];
		}
		
		if ((strcasecmp($typeMatch, "regularSeason") == 0)&&((strcasecmp($league1, $league2) != 0))) {
			die("Error : During the Regular Season, teams of different league can not play against each other");
		}
		if ((strcasecmp($typeMatch, "playOffs") == 0)&&((strcasecmp($league1, $league2) == 0))) {
			die("Error : During the Play Offs, teams of the same league can not play against each other");
		}
		
		$reponse1->free();
		$reponse2->free();
	}
	
	// fonction qui cree les matchs avec des INSERT
	function creerMatches($link,$team1,$date1,$team2,$date2,$typeMatch,$ptl1,$ptv1,$ptl2,$ptv2){
		$id1;$id2;
		if(strcasecmp($typeMatch, "playOffs") == 0){
			$id1="PO";
			$id2="PO";
		}
		
		$ident1;$ident2;
		$requete1="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$team1\"";
		$reponse1 = $link->query($requete1) or die("Error SQL Select joueur,equipe: ". $link->error);
		if($donnees = $reponse1->fetch_assoc()){
			$ident=$donnees['identificateur_stats'];
			$ident1=$ident[0].$ident[1];
		}
		$requete2="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$team2\"";
		$reponse2 = $link->query($requete2) or die("Error SQL Select joueur,equipe: ". $link->error);
		if($donnees = $reponse2->fetch_assoc()){
			$ident=$donnees['identificateur_stats'];
			$ident2=$ident[0].$ident[1];
		}
		
		$id1=$id1.$date1[0].$date1[1].$date1[3].$date1[4].$ident1.$ident2;
		$id2=$id2.$date2[0].$date2[1].$date2[3].$date2[4].$ident2.$ident1;
		
		$requete3="SELECT matchs.identificateur_match FROM matchs WHERE matchs.identificateur_match=\"$id1\"";
		$reponse3 = $link->query($requete3) or die("Error SQL Select matchs: ". $link->error);
		if($donnees = $reponse3->fetch_assoc()){
			die("Error : the first match already exists. ");
		}
		
		$requete4="SELECT matchs.identificateur_match FROM matchs WHERE matchs.identificateur_match=\"$id2\"";
		$reponse4 = $link->query($requete4) or die("Error SQL Select matchs: ". $link->error);
		if($donnees = $reponse4->fetch_assoc()){
			die("Error : the second match already exists. ");
		}
		$requete5="INSERT INTO matchs VALUES (\"$id1\", \"$date1\", \"$team1\",\"$team2\", $ptl1,$ptv1)";
		$reponse5 = $link->query($requete5)or die("Error Insert First Match: ". $link->error);
		$requete6="INSERT INTO matchs VALUES (\"$id2\", \"$date2\", \"$team2\",\"$team1\", $ptl2,$ptv2)";
		$reponse6 = $link->query($requete6)or problemeInsertMatch("Error Insert Second Match: ". $link->error,$link,$id1);
		printf("Insert Matches Success ");
		
		
		$reponse1->free();
		$reponse2->free();
		$reponse3->free();
		$reponse4->free();
		$reponse5->free();
		$reponse6->free();
	}
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
			
			<p>
			<?php
				$team1=$_POST['team1'];
				$team2=$_POST['team2'];
				$type=$_POST['typeMatch'];
				$ptl1=$_POST['score_aller1'];
				$ptv1=$_POST['score_aller2'];
				$date1=$_POST['date_aller'];
				$ptl2=$_POST['score_retour2'];
				$ptv2=$_POST['score_retour1'];
				$date2=$_POST['date_retour'];
				verifierScores($ptl1,$ptv1,$ptl2,$ptv2);
				verifierDates($date1,$date2);
				verifierAdversaires($link,$team1,$team2,$type);
				creerMatches($link,$team1,$date1,$team2,$date2,$type,$ptl1,$ptv1,$ptl2,$ptv2);
				$link->close();
			?>
			</p>
			
	</body> 

</html> 
