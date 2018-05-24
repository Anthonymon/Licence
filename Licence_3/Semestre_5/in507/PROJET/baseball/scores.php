<?php
ini_set('display_errors','off');
 
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Scores
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
		<!-- On recherche les differents classements pour les afficher sur la page -->
		<?php
			$reponse1 = $link->query('SELECT Classement_poules.ville, Classement_poules.PT FROM Classement_poules WHERE Classement_poules.league="national" ORDER BY Classement_poules.PT DESC')or die("Error SQL Select Classement: ". $link->error);
			$reponse2 = $link->query('SELECT Classement_poules.ville, Classement_poules.PT FROM Classement_poules WHERE Classement_poules.league="american" ORDER BY Classement_poules.PT DESC')or die("Error SQL Select Classement: ". $link->error);
			$reponse3 = $link->query('SELECT * FROM Classement_playoff')or die("Error SQL Select Classement: ". $link->error);
		?>

		<p>
		<img class="championnat" src="img/autres/resultats.png" >
		<br><br><br><br><br><br><br>
		<table> 
			<tr> 
				<th class="scoresLeagueTab">National League</th> 
				<th class="scoresPointsTab">Points</th> 
				<th class="tailleEspaceScores"> </th>
				<th class="scoresPointsTab">Points</th>
				<th class="scoresLeagueTab">American League</th>
			</tr>
				
			<?php
				$compteurNational=0;
				$compteurBoucleNational=0;
				// on voit regarder le classement national ET american
				while ($donnees1 = $reponse1->fetch_assoc()){
						$nationalVille[$compteurNational]=$donnees1['ville'];
						$nationalPT[$compteurNational]=$donnees1['PT'];
						$compteurNational=$compteurNational+1;
				} 
				
				$compteurAmerican=0;
				$compteurBoucleAmerican=0;
				while ($donnees2 = $reponse2->fetch_assoc()){
					$americanVille[$compteurAmerican]=$donnees2['ville'];
					$americanPT[$compteurAmerican]=$donnees2['PT'];
					$compteurAmerican=$compteurAmerican+1;
				}
					
				$premierNationalScore;
				$premierNationalNom;
				$deuxiemeNationalScore;
				$deuxiemeNationalNom;
				$urlPremierNational;
				$urlDeuxiemeNational;
					
				$premierAmericanScore;
				$premierAmericanNom;
				$deuxiemeAmericanScore;
				$deuxiemeAmericanNom;
				$urlPremierAmerican;
				$urlDeuxiemeAmerican;
					
				while(($compteurBoucleNational<$compteurNational)||($compteurBoucleAmerican<$compteurAmerican)){
					?>
					<tr> 
					<?php 
						if($compteurBoucleNational<$compteurNational){ ?>
							<td class="alignement"><?php printf("$nationalVille[$compteurBoucleNational]");?></td> 
							<td class="alignement"><?php printf("$nationalPT[$compteurBoucleNational]");?></td> 
							<?php 
						}
						else { ?>
							<td class="alignement"> </td> 
							<td class="alignement"> </td>
							<?php 
						} ?>
						<td width="900px"> </td>
						<?php 
						if($compteurBoucleAmerican<$compteurAmerican){ ?>
							<td class="alignement"><?php printf("$americanPT[$compteurBoucleAmerican]");?></td> 
							<td class="alignement"><?php printf("$americanVille[$compteurBoucleAmerican]");?></td> 
							<?php 
						}
						else { ?>
							<td class="alignement"> </td> 
							<td class="alignement"> </td>
							<?php 
						} ?>
						<?php $compteurBoucleNational=$compteurBoucleNational+1; 
						$compteurBoucleAmerican=$compteurBoucleAmerican+1; ?>
						</tr> 
						<?php
				}?>
			</table> 
			
			 <?php
				// en fonction des resultats du classement les equipes vainqueurs sont affiches dans l'arbre
				$urlPremierNational="img/equipes/".str_replace(" ","_",$nationalVille[0]).".png";
				$urlDeuxiemeNational="img/equipes/".str_replace(" ","_",$nationalVille[1]).".png";
				$urlPremierAmerican="img/equipes/".str_replace(" ","_",$americanVille[0]).".png";
				$urlDeuxiemeAmerican="img/equipes/".str_replace(" ","_",$americanVille[1]).".png";
				printf("<img class=\"premierNational\" src=\"$urlPremierNational\" alt=\"$nationalVille[0]\">");
				printf("<img class=\"deuxiemeNational\" src=\"$urlDeuxiemeNational\" alt=\"$nationalVille[1]\">");
				printf("<img class=\"premierAmerican\" src=\"$urlPremierAmerican\" alt=\"$americanVille[0]\">");
				printf("<img class=\"deuxiemeAmerican\" src=\"$urlDeuxiemeAmerican\" alt=\"$americanVille[1]\">");

				$scorePlayoffPremierNational;
				$scorePlayoffDeuxiemeNational;
				$scorePlayoffPremierAmerican;
				$scorePlayoffDeuxiemeAmerican;
				while ($donnees3 = $reponse3->fetch_assoc()){
					if($donnees3['ville']==$nationalVille[0]){
						$scorePlayoffPremierNational=$donnees3['PT'];
					}
					if($donnees3['ville']==$americanVille[0]){
						$scorePlayoffPremierAmerican=$donnees3['PT'];
					}
					if($donnees3['ville']==$nationalVille[1]){
						$scorePlayoffDeuxiemeNational=$donnees3['PT'];
					}
					if($donnees3['ville']==$americanVille[1]){
						$scorePlayoffDeuxiemeAmerican=$donnees3['PT'];
					}
				}
				if($scorePlayoffPremierNational>=$scorePlayoffPremierAmerican){
					$photo5="img/equipes/".str_replace(" ","_",$nationalVille[0]).".png";
					printf("<img class=\"premierClassement\" src=\"$photo5\" alt=\"$nationalVille[0]\">");
				}
				else{
					$photo6="img/equipes/".str_replace(" ","_",$americanVille[0]).".png";
					printf("<img class=\"premierClassement\" src=\"$photo6\" alt=\"$americanVille[0]\">");
				}
				if($scorePlayoffDeuxiemeNational>=$scorePlayoffDeuxiemeAmerican){
					$photo7="img/equipes/".str_replace(" ","_",$nationalVille[1]).".png";
					printf("<img class=\"troisiemeClassement\" src=\"$photo7\" alt=\"$nationalVille[1]\">");
				}
				else{
					$photo8="img/equipes/".str_replace(" ","_",$americanVille[1]).".png";
					printf("<img class=\"troisiemeClassement\" src=\"$photo8\" alt=\"$americanVille[1]\">");
				} ?>
			</p>
		
		<p>
		<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
		<table>
			<!-- On affiche aussi tous les matchs du championnat -->
			<h2 class="titre">Matches</h2>
			<tr> 
				<th class="espaceMatchsScores"></th>
				<th class="roasterTabMatchs">Season</th>
				<th class="roasterTabMatchs">Date</th> 
				<th class="roasterTabMatchs">Local</th> 
				<th class="roasterTabMatchs">Score</th>
				<th class="roasterTabMatchs">Visitor</th>
			</tr> 
			<?php
				$requete="SELECT matchs.* FROM matchs";
				$reponse1 = $link->query($requete)or die("Error SQL Select matchs,equipe: ". $link->error); 
		
				while ($donnees2 = $reponse1->fetch_assoc()){ ?>
					<tr>
						<td></td> 
						<?php
							if(($donnees2['identificateur_match'][0]=='P')&&($donnees2['identificateur_match'][1]=='O')){ ?>
								<td class="alignement">Post Season</td>
								<?php 
							}
							else{ ?>
								<td class="alignement">Regular Season</td>
								<?php 
							}?>
						<td class="alignement"><?php printf($donnees2['date_match']);?></td> 
						<td class="alignement"><?php printf($donnees2['local_match']);?></td>
						<td class="alignement"><?php printf($donnees2['ptl']);printf(" - ");printf($donnees2['ptv'])?></td>
						<td class="alignement"><?php printf($donnees2['visiteur_match']);?></td>
					</tr>
					<?php 
				} ?>
			</table>
			</p>

		<?php
			$link->close();
			$reponse1->free();
			$reponse2->free();
			$reponse3->free();
		?>	
	</body> 

</html> 
