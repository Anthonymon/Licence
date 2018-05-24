<?php
	ini_set('display_errors','off');
?>

<?php

	function afficher_recherche($reponse,$findme){
		while ($donnees = $reponse->fetch_assoc()){ 
			if(((strpos(strtolower($donnees['nom_joueur']), strtolower($findme)))!==false)||((strpos(strtolower($donnees['prenom_joueur']), strtolower($findme)))!==false)){ ?>
				<?php $photo="img/joueurs/".str_replace(" ","_",$donnees['ville'])."/".$donnees['identificateur_stats'].".jpg"; ?>
				<tr>
					<td class="alignement">
						<form method="POST" action="player.php">
							<input type="hidden" name="username" value="<?php print $_POST['username']?>">
							<input type="hidden" name="password" value="<?php print $_POST['password']?>">
							<input type="hidden" name="nomJoueur" value="<?php print $donnees['nom_joueur']?>">
							<input type="hidden" name="ville" value="<?php print $donnees['ville']?>">
							<input class="photoJoueur" type="image" name="boutonVoir" src="img/autres/bouton_voir.png"> 
							<img class="photoJoueur" src=<?php printf("$photo") ?> alt=\"Player">
						</form>
					</td>
					<td class="alignement"> <?php echo $donnees['nom_joueur'];?> </td> 
					<td class="alignement"> <?php echo $donnees['prenom_joueur']; ?> </td> 
					<td class="alignement"> <?php echo $donnees['numero'];?> </td> 
					<td class="alignement"> <?php echo $donnees['poste'];?> </td> 
					<td class="alignement"> <?php echo $donnees['ville'];?> </td> 
					<td class="alignement"> <?php echo $donnees['age'];?> </td> 
					<td class="alignement"> <?php echo $donnees['AB'];?> </td> 
					<td class="alignement"> <?php echo $donnees['AVG'];?> </td> 
					<td class="alignement"> <?php echo $donnees['HR'];?> </td> 
					<td class="alignement"> <?php echo $donnees['RBI'];?> </td> 
					<td class="alignement"> <?php echo $donnees['SB'];?> </td> 
					<td class="alignement"> <?php echo $donnees['OPS'];?> </td> 
					<?php
						if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
							<td class="alignement">
								<form method="POST" action="modification_stats.php">
									<input type="hidden" name="username" value="<?php print $_POST['username']?>">
									<input type="hidden" name="password" value="<?php print $_POST['password']?>">
									<input type="hidden" name="nomJoueur" value="<?php print $donnees['nom_joueur']?>">
									<input type="hidden" name="ville" value="<?php print $donnees['ville']?>">
									<input class="boutons" type="image" name="boutonEdit" src="img/autres/bouton_edit.png"> 
								</form>
							</td>
							<?php 
						}?>
						</tr> <?php
			}
			
		}
		printf("</table></p>");
	}

	function afficher_joueurs($reponse){
		// On affiche chaque entrée une à une
		while ($donnees = $reponse->fetch_assoc()){ ?>
			<?php $photo="img/joueurs/".str_replace(" ","_",$donnees['ville'])."/".$donnees['identificateur_stats'].".jpg"; ?>
			
				<tr>
					<td class="alignement">
						<form method="POST" action="player.php">
							<input type="hidden" name="username" value="<?php print $_POST['username']?>">
							<input type="hidden" name="password" value="<?php print $_POST['password']?>">
							<input type="hidden" name="nomJoueur" value="<?php print $donnees['nom_joueur']?>">
							<input type="hidden" name="ville" value="<?php print $donnees['ville']?>">
							<input class="photoJoueur" type="image" name="boutonVoir" src="img/autres/bouton_voir.png"> 
							<img class="photoJoueur" src=<?php printf("$photo") ?> alt=\"Player">
						</form>
					</td>
					<td class="alignement"> <?php echo $donnees['nom_joueur'];?> </td> 
					<td class="alignement"> <?php echo $donnees['prenom_joueur']; ?> </td> 
					<td class="alignement"> <?php echo $donnees['numero'];?> </td> 
					<td class="alignement"> <?php echo $donnees['poste'];?> </td> 
					<td class="alignement"> <?php echo $donnees['ville'];?> </td> 
					<td class="alignement"> <?php echo $donnees['age'];?> </td> 
					<td class="alignement"> <?php echo $donnees['AB'];?> </td> 
					<td class="alignement"> <?php echo $donnees['AVG'];?> </td> 
					<td class="alignement"> <?php echo $donnees['HR'];?> </td> 
					<td class="alignement"> <?php echo $donnees['RBI'];?> </td> 
					<td class="alignement"> <?php echo $donnees['SB'];?> </td> 
					<td class="alignement"> <?php echo $donnees['OPS'];?> </td> 
					<?php
						if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
							<td class="alignement">
								<form method="POST" action="modification_stats.php">
									<input type="hidden" name="username" value="<?php print $_POST['username']?>">
									<input type="hidden" name="password" value="<?php print $_POST['password']?>">
									<input type="hidden" name="nomJoueur" value="<?php print $donnees['nom_joueur']?>">
									<input type="hidden" name="ville" value="<?php print $donnees['ville']?>">
									<input class="boutons" type="image" name="boutonEdit" src="img/autres/bouton_edit.png"> 
								</form>
							</td>
							<?php 
						}?>
						</tr> <?php
		}
		printf("</table></p>");
	}
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Stats
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
		
		<form method="post" action="stats.php">
			<input type="hidden" name="username" value="<?php print $_POST['username']?>">
			<input type="hidden" name="password" value="<?php print $_POST['password']?>">
			<p> Search Position : &nbsp;&nbsp;
			<select id="genre" name="poste" required>
				<option value ="P" selected> Pitcher
				<option value ="C"> Catcher
				<option value ="1B"> First Base
				<option value ="2B"> Second Base
				<option value ="3B"> Third Base
				<option value ="SS"> Short Stop
				<option value ="LF"> Left Field
				<option value ="CF"> Center Field
				<option value ="RF"> Right Field
				</option>
			</select>
			&nbsp;&nbsp;&nbsp;
			<input value="Show" type="submit">
			</p>
		</form>
		
		<form method="post" action="stats.php">
			<input type="hidden" name="username" value="<?php print $_POST['username']?>">
			<input type="hidden" name="password" value="<?php print $_POST['password']?>">
			<p> Search Player : &nbsp;&nbsp;
			<input type="text" name="searchPlayer" placeholder="Name" required>
			&nbsp;&nbsp;&nbsp;
			<input value="Show" type="submit">
			</p>
		</form>

		<p>
		<table > <!-- On va afficher chaque statistique de chaque joueur -->
			<tr class="coulStats"> 
				<th class="tailleTabStats">Player</th>
                <th class="tailleTabStats">Last Name</th> 
                <th class="tailleTabStats">First Name</th> 
                <th class="tailleTabStats">Number</th> 
                <th class="tailleTabStats">Position</th> 
                <th class="tailleTabStats">City</th> 
                <th class="tailleTabStats">Age</th> 
                <th class="tailleTabStats">AB</th> 
                <th class="tailleTabStats">AVG</th> 
                <th class="tailleTabStats">HR</th> 
                <th class="tailleTabStats">RBI</th> 
                <th class="tailleTabStats">SB</th> 
                <th class="tailleTabStats">OPS</th> 
                 <?php
					if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
						<th class="tailleTabStats">Edit</th>
						<?php 
					}?>		
				<?php
					
					if(isset($_POST['poste'])){
						$requete="SELECT Infos_joueurs.*,stats.identificateur_stats FROM Infos_joueurs,stats,joueur WHERE stats.identificateur_stats=joueur.identificateur_stats AND Infos_joueurs.nom_joueur=joueur.nom_joueur AND Infos_joueurs.prenom_joueur=joueur.prenom_joueur AND joueur.poste=\"".$_POST['poste']."\"";
						$reponse = $link->query($requete)or die("Error SQL Select stats: ". $link->error);
						afficher_joueurs($reponse);
					}
					
					else if(isset($_POST['searchPlayer'])){
						$rechercheJou=$_POST['searchPlayer'];
						$reponse = $link->query('SELECT Infos_joueurs.*,stats.identificateur_stats FROM Infos_joueurs,stats,joueur WHERE stats.identificateur_stats=joueur.identificateur_stats AND Infos_joueurs.nom_joueur=joueur.nom_joueur AND Infos_joueurs.prenom_joueur=joueur.prenom_joueur')or die("Error SQL Select stats: ". $link->error);
						afficher_recherche($reponse,$rechercheJou);
					}
					
					// On récupère le contenu de la table stats et de la vue Infos_joueurs
					else{
						$reponse = $link->query('SELECT Infos_joueurs.*,stats.identificateur_stats FROM Infos_joueurs,stats,joueur WHERE stats.identificateur_stats=joueur.identificateur_stats AND Infos_joueurs.nom_joueur=joueur.nom_joueur AND Infos_joueurs.prenom_joueur=joueur.prenom_joueur')or die("Error SQL Select stats: ". $link->error);
						afficher_joueurs($reponse);
					}
					 
					$reponse->free();
					$link->close(); ?>
		<br>
	</body> 

</html> 
