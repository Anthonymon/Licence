<?php
ini_set('display_errors','off');
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Teams
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
		
		<!-- Si l'utilisateur a les droits il pourra creer une equipe -->
		<?php
			if(($_POST['username']=="root2")||($_POST['username']=="mlbbaseball")){ ?>
				<p>
				<form method="POST" action="creation_team.php">
					<input type="hidden" name="username" value="<?php print $_POST['username']?>">
					<input type="hidden" name="password" value="<?php print $_POST['password']?>">
					<input type="submit" value="Create a new Team"> 
				</form>
				</p>
				<?php 
			}?>
			
			<p>
			<table> <!-- Pour chaque equipe on va afficher ses informations ainsi que des boutons pour pouvoir les manipuler -->
				<tr>
					<th class="teamsEcart"></th> 
					<th class="teamsTabInfos">City</th> 
					<th class="teamsTabInfos">Emblem</th> 
					<th class="teamsTabBoutons">League</th>
					<th class="teamsTabBoutons">Roster</th>
					<?php
						if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
							<th class="teamsTabBoutons">Delete</th>
							<th class="teamsTabBoutons">Edit</th>
							<?php 
						}?>
				</tr> 			
				<?php
					// On récupère tout le contenu de la table equipe avec la league american
					$reponse1 = $link->query('SELECT * FROM equipe WHERE equipe.league="american"') or die("Error SQL Select equipe: ". $link->error);

					while ($donnees1 = $reponse1->fetch_assoc()){
				?>		
				<tr>
					<td></td>
					<td class="alignement"><?php printf($donnees1['ville']);?></td>
					<?php $photo1="img/equipes/".str_replace(" ","_",$donnees1['ville']).".png"; ?>
					<td class="alignement"><img class="imageEquipe" src=<?php printf("$photo1") ?> alt="<?php print $donnees1['ville']?>"></td>
					<td class="alignement"><?php printf($donnees1['league']);?></td>
					<td class="alignement">
						
					<form method="POST" action="roster.php">
						<input type="hidden" name="username" value="<?php print $_POST['username']?>">
						<input type="hidden" name="password" value="<?php print $_POST['password']?>">
						<input type="hidden" name="equipe" value="<?php print $donnees1['ville']?>">
						<input class="boutons" type="image" name="boutonVoir" src="img/autres/bouton_voir.png"> 
					</form>
					</td>
					
					<?php
						if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
							<td class="alignement">
							<form method="POST" action="suppression_team.php">
								<input type="hidden" name="username" value="<?php print $_POST['username']?>">
								<input type="hidden" name="password" value="<?php print $_POST['password']?>">
								<input type="hidden" name="equipe" value="<?php print $donnees1['ville']?>">
								<input class="boutons" type="image" name="boutonSuppr" src="img/autres/bouton_suppr.png"> 
							</form>
							</td>
							<td class="alignement">
								<form method="POST" action="modification_team.php">
									<input type="hidden" name="username" value="<?php print $_POST['username']?>">
									<input type="hidden" name="password" value="<?php print $_POST['password']?>">
									<input type="hidden" name="equipe" value="<?php print $donnees1['ville']?>">
									<input class="boutons" type="image" name="boutonEdit" src="img/autres/bouton_edit.png"> 
								</form>
							</td>
							<?php 
						}?> <?php
					}
				
				// On récupère tout le contenu de la table equipe avec la league national
				$reponse2 = $link->query('SELECT * FROM equipe WHERE equipe.league="national"') or die("Error SQL Select equipe: ". $link->error); 
				while ($donnees2 = $reponse2->fetch_assoc()){ ?>		
					<tr>
						<td></td>
						<td class="alignement"><?php printf($donnees2['ville']);?></td>
						<?php $photo2="img/equipes/".str_replace(" ","_",$donnees2['ville']).".png"; ?>
						<td class="alignement"><img class="imageEquipe" src=<?php printf("$photo2") ?>></td>
						<td class="alignement"><?php printf($donnees2['league']);?></td>
						<td class="alignement">
						<form method="POST" action="roster.php">
							<input type="hidden" name="username" value="<?php print $_POST['username']?>">
							<input type="hidden" name="password" value="<?php print $_POST['password']?>">
							<input type="hidden" name="equipe" value="<?php print $donnees2['ville']?>">
							<input class="boutons" type="image" name="boutonVoir" src="img/autres/bouton_voir.png"> 
						</form>
						</td>
			
					<?php
					if(($_POST['username']=="root2")||($_POST['username']=="user")||($_POST['username']=="mlbbaseball")){ ?>
						<td class="alignement">
						<form method="POST" action="suppression_team.php"> <!-- a modifier -->
							<input type="hidden" name="username" value="<?php print $_POST['username']?>">
							<input type="hidden" name="password" value="<?php print $_POST['password']?>">
							<input type="hidden" name="equipe" value="<?php print $donnees2['ville']?>">
							<input class="boutons" type="image" name="boutonSuppr" src="img/autres/bouton_suppr.png"> 
						</form>
						</td>
						<td class="alignement">
						<form method="POST" action="modification_team.php"> <!-- a modifier -->
							<input type="hidden" name="username" value="<?php print $_POST['username']?>">
							<input type="hidden" name="password" value="<?php print $_POST['password']?>">
							<input type="hidden" name="equipe" value="<?php print $donnees2['ville']?>">
							<input class="boutons" type="image" name="boutonEdit" src="img/autres/bouton_edit.png"> 
						</form>
						</td>
						<?php 
					}?>
				<?php
				}
		
		$link->close();
		$reponse1->free();
		$reponse2->free();
		?>
		</table> 
		</p><br><br>
	</body> 

</html> 
