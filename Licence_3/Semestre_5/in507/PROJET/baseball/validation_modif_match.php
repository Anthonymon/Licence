
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
				<!-- Mise a jour du match choisi-->
				<?php
					$ptl=$_POST['newPtl'];
					$ptv=$_POST['newPtv'];
					if($ptl==$ptv) die("Match can not be draw");
					$id=$_POST['iden'];
					$requete="UPDATE matchs SET ptl=\"$ptl\",ptv=\"$ptv\" WHERE matchs.identificateur_match=\"$id\"";
					$link->query($requete)or die("Error Update Match: ". $link->error);
					printf("Match Updated "."<br><br>");
					$link->close();
				?>
			</p>
			
	</body> 

</html> 
