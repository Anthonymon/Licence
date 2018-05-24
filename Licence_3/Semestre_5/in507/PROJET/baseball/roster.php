<?php
ini_set('display_errors','off');
 
?>

<?php
	// Pour chaque joueur on affiche sa photo avec ses informations
	function afficher($urlPhoto,$requete,$reponse1,$nomEquipe,$class){
		if($donnees = $reponse1->fetch_assoc()){
				$urlPhoto="img/joueurs/".str_replace(" ","_",$nomEquipe)."/".$donnees['identificateur_stats'].".jpg";
				?>
				<img class="<?php printf($class)?>" src=<?php printf("$urlPhoto") ?> alt="Player">
				<tr>
					<td></td> 
					<td class="alignement">
						<form method="POST" action="player.php">
							<input type="hidden" name="username" value="<?php print $_POST['username']?>">
							<input type="hidden" name="password" value="<?php print $_POST['password']?>">
							<input type="hidden" name="nomJoueur" value="<?php print $donnees['nom_joueur']?>">
							<input type="hidden" name="ville" value="<?php print $nomEquipe?>">
							<input class="boutons" type="image" name="boutonVoir" src="img/autres/bouton_voir.png"> 
							<img class="photoJoueur" src=<?php printf("$urlPhoto") ?> alt="Player">
						</form>
					</td> 
					<td class="alignement"><?php printf($donnees['nom_joueur'])?></td>
					<td class="alignement"><?php printf($donnees['numero'])?></td>
					<td class="alignement"><?php printf($donnees['poste'])?></td>
				</tr>
				<?php
		}
		else { ?>
			<tr>
				<td></td> 
				<td class="alignement"></td> 
				<td class="alignement">-</td>
				<td class="alignement">-></td>
				<td class="alignement">-</td>
			</tr>
		<?php 
		}
	}
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Team
		</title>
	</head>

	<body> 
		<?php
			include("bordereau.php");
		?>
			
		<p>
		<?php $photo="img/equipes/".str_replace(" ","_",$_POST['equipe']).".png"; ?>
		<img class="presentationEquipe" src=<?php printf("$photo")?> alt="Team">
		<img class="roaster" src="img/autres/terrain.jpg">
			
		<table>
			<tr> 
				<th class="roasterEcart"></th> 
                <th class="teamsTabBoutons"></th> 
                <th class="teamsTabBoutons">Player</th>
                <th class="teamsTabBoutons">Number</th>
                <th class="teamsTabBoutons">Position</th>
			</tr> 
			
			<?php
			$urlPhoto;
			$nomEquipe=$_POST['equipe'];
			// on recherche les informations pour le coach ainsi que les 9 joueurs
			$requete="SELECT entraineur.prenom_entraineur,entraineur.nom_entraineur FROM entraineur,equipe WHERE equipe.nom_entraineur=entraineur.nom_entraineur AND equipe.prenom_entraineur=entraineur.prenom_entraineur AND equipe.ville=\"$nomEquipe\"";
			$reponse1 = $link->query($requete) or die("Error SQL Select entraineur,equipe: " .$link->error);
			if($donneesCoach = $reponse1->fetch_assoc()) { //affichage du coach
				$urlPhoto="img/coachs/".str_replace(" ","_",$nomEquipe)."_coach".".jpg";?>
				<img class="coach" src=<?php printf("$urlPhoto") ?>>
				<tr>
					<td></td> 
					<td class="alignement"><img class="photoJoueur" src=<?php printf("$urlPhoto") ?> alt="Coach"></td> 
					<td class="alignement"><?php printf($donneesCoach['nom_entraineur'])?></td>
					<td class="alignement">00</td>
					<td class="alignement">Coach</td>
				</tr>
				
				<?php
			}
			else { ?>
				<tr>
					<td></td> 
					<td class="alignement"></td> 
					<td class="alignement">-</td>
					<td class="alignement">-></td>
					<td class="alignement">-</td>
				</tr>
				<?php 
			}
			
			/* Affichage de chaque joueur */
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"P\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"pitcher");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"C\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"catcher");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"1B\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"firstBase");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"2B\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"secondBase");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"3B\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"thirdBase");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"SS\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"shortStop");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"LF\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"leftField");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"CF\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"centerField");
			
			$requete="SELECT joueur.* FROM joueur,equipe WHERE equipe.ville=joueur.ville AND equipe.ville=\"$nomEquipe\" AND joueur.poste=\"RF\"";
			$reponse1 = $link->query($requete)or die("Error SQL Select joueur,equipe: ". $link->error);
			afficher($urlPhoto,$requete,$reponse1,$nomEquipe,"rightField");
			?>
		</table>
		</p>
			
		<?php
			if(($_POST['username']=="root2")||($_POST['username']=="mlbbaseball")){ ?>
				<p>
				<br><br><br>
				<!-- Bouton pour creer des matchs-->
				<form method="POST" action="creation_match.php">
					<input type="hidden" name="username" value="<?php print $_POST['username']?>">
					<input type="hidden" name="password" value="<?php print $_POST['password']?>">
					<input type="hidden" name="equipe" value="<?php print $nomEquipe?>">
					<input type="submit" value="Create Matches"> 
				</form>
				</p>
				<?php 
			}?>
			
			<p> <!-- On affiche les informations des matchs de l'equipe -->
			<table>
				<h2 class="titre">Matches</h2>
				<tr> 
					<th class="tailleTabMatchs"></th>
					<th class="roasterTabMatchs">Season</th>
					<th class="roasterTabMatchs">Date</th> 
					<th class="roasterTabMatchs">Local</th> 
					<th class="roasterTabMatchs">Score</th>
					<th class="roasterTabMatchs">Visitor</th>
					 <?php
					if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
						<th class="teamsTabBoutons">Delete</th>
						<th class="teamsTabBoutons">Edit</th>
					<?php }?>
				</tr> 
				
				<?php
				$requete="SELECT matchs.* FROM matchs, equipe WHERE (matchs.local_match=equipe.ville OR matchs.visiteur_match=equipe.ville) AND equipe.ville=\"$nomEquipe\"";
				$reponse1 = $link->query($requete)or die("Error SQL Select matchs,equipe: " . $link->error); 
		
		while ($donnees = $reponse1->fetch_assoc()){ ?>
			<tr>
				<td></td> 
					<?php
						if(($donnees['identificateur_match'][0]=='P')&&($donnees['identificateur_match'][1]=='O')){ ?>
							<td class="alignement">Post Season</td>
							<?php 
						}
						else{ ?>
							<td class="alignement">Regular Season</td>
							<?php 
						}?>
						<td class="alignement"><?php printf($donnees['date_match']);?></td> 
						<td class="alignement"><?php printf($donnees['local_match']);?></td>
						<td class="alignement"><?php printf($donnees['ptl']);printf(" - ");printf($donnees['ptv'])?></td>
						<td class="alignement"><?php printf($donnees['visiteur_match']);?></td>
					
						<?php
						if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){
							?>
							<td class="alignement">
								<!-- Pour chaque match on peut le supprimer ou modifier le score -->
								<form method="POST" action="suppression_match.php">
									<input type="hidden" name="username" value="<?php print $_POST['username']?>">
									<input type="hidden" name="password" value="<?php print $_POST['password']?>">
									<input type="hidden" name="id" value="<?php print $donnees['identificateur_match']?>">
									<input class="boutons" type="image" name="boutonSuppr" src="img/autres/bouton_suppr.png"> 
								</form>
							</td>
							<td class="alignement">
								<form method="POST" action="modification_match.php">
									<input type="hidden" name="username" value="<?php print $_POST['username']?>">
									<input type="hidden" name="password" value="<?php print $_POST['password']?>">
									<input type="hidden" name="id" value="<?php print $donnees['identificateur_match']?>">
									<input class="boutons" type="image" name="boutonEdit" src="img/autres/bouton_edit.png"> 
								</form>
							</td>
							<?php 
						}?>
						</tr>
					<?php 
		} ?>
		</table>
		</p>
			
		<br><br>
		<p>
		<table> <!-- On ecrit les stats de l'equipe-->
			<h2 class="titre">Team statistics</h2>
			<tr> 
				<th class="tailleTabStatsRoaster"></th>
				<th class="teamsTabBoutons">AB</th> 
				<th class="teamsTabBoutons">AVG</th> 
				<th class="teamsTabBoutons">HR</th> 
				<th class="teamsTabBoutons">RBI</th> 
				<th class="teamsTabBoutons">SB</th> 
				<th class="teamsTabBoutons">OPS</th>
			</tr> 
				
				
			<?php
				$requete="SELECT CAST(AVG(stats.AB)AS DECIMAL(10,0)) AS AB, CAST(AVG(stats.AVG_stats)AS DECIMAL(10,3)) AS AVG, CAST(AVG(stats.HR)AS DECIMAL(10,0)) AS HR, CAST(AVG(stats.RBI)AS DECIMAL(10,0)) AS RBI, CAST(AVG(SB) AS DECIMAL(10,0)) AS SB, CAST(AVG(OPS)AS DECIMAL(10,0)) AS OPS FROM stats,joueur WHERE stats.identificateur_stats=joueur.identificateur_stats AND joueur.ville=\"$nomEquipe\"";
				$reponse1 = $link->query($requete) or die("Error SQL Select joueur,stats: ". $link->error); 
		
			if ($donnees = $reponse1->fetch_assoc()){ ?>
				<tr>
					<td></td> 
					<td class="alignement"><?php printf($donnees['AB']);?></td> 
					<td class="alignement"><?php printf($donnees['AVG']);?></td>
					<td class="alignement"><?php printf($donnees['HR']);?></td>
					<td class="alignement"><?php printf($donnees['RBI']);?></td>
					<td class="alignement"><?php printf($donnees['SB']);?></td>
					<td class="alignement"><?php printf($donnees['OPS']);?></td>
				</tr>
				<?php 
			} ?>
		</table>
		</p>
			
		<?php 
			$link->close();
			$reponse1->free();
		?>
	</body> 

</html> 
