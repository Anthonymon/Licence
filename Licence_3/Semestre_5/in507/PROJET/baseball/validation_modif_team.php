<?php
ini_set('display_errors','off');
?>

<html> 
	<head>
		<link rel="stylesheet" href="style.css" type="text/css"> 
		<title>
			Team Modification
		</title>
	</head>
	<body> 
		<?php
			include("bordereau.php");
			?>
			
			<p>
				<?php
					$ville=$_POST['villeEquipe'];
					$nomVille=$_POST['nomEquipe'];
					$ancienNomEntraineur=$_POST['ancienNomEntraineur'];
					$ancienPrenomEntraineur=$_POST['ancienPrenomEntraineur'];
					$nomEntraineur=$_POST['nomEntraineur'];
					$prenomEntraineur=$_POST['prenomEntraineur'];
				
					//mise a jour de la ville et du nom de l'equipe
					$ancienNomVille=$_POST['ancienNomVille'];
					$updateVille="UPDATE equipe SET ville=\"$ville\",nom=\"$nomVille\" WHERE ville=\"$ancienNomVille\"";
					$result=$link->query($updateVille)or die("Error SQL Update equipe: this city already exists ");
					printf("Updating Name Team Success. ");
					printf("<br><br>");
					
					//mise a jour de lentraineur
					$result=$link->query("UPDATE entraineur SET nom_entraineur=\"$nomEntraineur\",prenom_entraineur=\"$prenomEntraineur\" WHERE nom_entraineur=\"$ancienNomEntraineur\" AND prenom_entraineur=\"$ancienPrenomEntraineur\"")or die("Error SQL Update entraineur : this coach already exists in an other team ");
					printf("Updating Coach Success. ");
					
					$result->free();
					$link->close();
				?>
			</p>
			
	</body> 

</html> 
