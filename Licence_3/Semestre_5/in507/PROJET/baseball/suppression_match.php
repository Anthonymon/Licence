<?php
	ini_set('display_errors','off');
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Match Delete
		</title>
	</head>
	
	<body> 
		<?php
			include("bordereau.php");
		?>
		<p>
		<?php
			// on supprime le match choisi par l'utilisateur
			$id=$_POST['id'];
			$requete="DELETE FROM matchs WHERE matchs.identificateur_match=\"$id\"";
			$link->query($requete)or die("Deleting Match Failed: ". $link->error);
			printf("Deleting Match Success. ");
			printf("<br>");
			$link->close();
		?>
		</p>		
	</body> 

</html> 
