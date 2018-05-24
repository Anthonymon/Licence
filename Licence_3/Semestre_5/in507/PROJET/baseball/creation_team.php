<?php
ini_set('display_errors','off');
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
		
		<!-- Formulaire pour creer l'equipe complete -->
		<form method="post" action="validation_creation_team.php">
			<input type="hidden" name="username" value="<?php print $_POST['username']?>">
			<input type="hidden" name="password" value="<?php print $_POST['password']?>">
			Team Creation : &nbsp;
			<input type="text" name="ville" placeholder="City" required> 
			&nbsp;
			<input type="text" name="nomVille" placeholder="Name" required>
			&nbsp;
			<select id="genre" name="league" required>
				<option value ="american" selected> American
				<option value ="national"> National</option>
			</select><br><br> <!-- Creation du coach -->
			Coach : &nbsp;
			<input type="text" name="nomCoach" placeholder="Last Name" required> 
			&nbsp;
			<input type="text" name="prenomCoach" placeholder="First Name" required>
			&nbsp;
			<input type="number" name="anneesCarriere" placeholder="Career Year(s)" min=0 required>
			&nbsp;
			<br><br><br><hr><hr><br><br> <!-- Creation P -->
			Pitcher : &nbsp;
			<input type="text" name="nom1" placeholder="Last Name Pitcher" required> 
			&nbsp;
			<input type="text" name="prenom1" placeholder="First Name Pitcher" required> 
			&nbsp;
			<input type="number" name="age1" placeholder="Pitcher Age" min=18 required>
			&nbsp;
			<input type="number" name="num1" placeholder="Pitcher Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB1" placeholder="Pitcher AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG1" placeholder="Pitcher AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR1" placeholder="Pitcher HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI1" placeholder="Pitcher RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB1" placeholder="Pitcher SB" min=0 required >
			&nbsp;
			<input type="number" name="OPS1" placeholder="Pitcher OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation C -->
		
			Catcher : &nbsp;
			<input type="text" name="nom2" placeholder="Last Name Catcher" required> 
			&nbsp;
			<input type="text" name="prenom2" placeholder="First Name Catcher" required> 
			&nbsp;
			<input type="number" name="age2" placeholder="Catcher Age" min=18 required>
			&nbsp;
			<input type="number" name="num2" placeholder="Catcher Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB2" placeholder="Catcher AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG2" placeholder="Catcher AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR2" placeholder="Catcher HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI2" placeholder="Catcher RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB2" placeholder="Catcher SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS2" placeholder="Catcher OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation 1B -->
		
			First Base : &nbsp;
			<input type="text" name="nom3" placeholder="Last Name 1B" required> 
			&nbsp;
			<input type="text" name="prenom3" placeholder="First Name 1B" required> 
			&nbsp;
			<input type="number" name="age3" placeholder="1B Age" min=18 required>
			&nbsp;
			<input type="number" name="num3" placeholder="1B Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB3" placeholder="1B AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG3" placeholder="1B AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR3" placeholder="1B HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI3" placeholder="1B RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB3" placeholder="1B SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS3" placeholder="1B OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation 2B -->
		
			Second Base : &nbsp;
			<input type="text" name="nom4" placeholder="Last Name 2B" required> 
			&nbsp;
			<input type="text" name="prenom4" placeholder="First Name 2B" required> 
			&nbsp;
			<input type="number" name="age4" placeholder="2B Age" min=18 required>
			&nbsp;
			<input type="number" name="num4" placeholder="2B Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB4" placeholder="2B AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG4" placeholder="2B AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR4" placeholder="2B HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI4" placeholder="2B RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB4" placeholder="2B SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS4" placeholder="2B OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation 3B -->
		
			Third Base : &nbsp;
			<input type="text" name="nom5" placeholder="Last Name 3B" required> 
			&nbsp;
			<input type="text" name="prenom5" placeholder="First Name 3B" required> 
			&nbsp;
			<input type="number" name="age5" placeholder="3B Age" min=18 required>
			&nbsp;
			<input type="number" name="num5" placeholder="3B Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB5" placeholder="3B AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG5" placeholder="3B AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR5" placeholder="3B HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI5" placeholder="3B RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB5" placeholder="3B SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS5" placeholder="3B OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation SS -->
		
			Short Stop : &nbsp;
			<input type="text" name="nom6" placeholder="Last Name SS" required> 
			&nbsp;
			<input type="text" name="prenom6" placeholder="First Name SS" required> 
			&nbsp;
			<input type="number" name="age6" placeholder="SS Age" min=18 required>
			&nbsp;
			<input type="number" name="num6" placeholder="SS Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB6" placeholder="SS AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG6" placeholder="SS AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR6" placeholder="SS HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI6" placeholder="SS RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB6" placeholder="SS SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS6" placeholder="SS OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation LF -->
		
			Left Field : &nbsp;
			<input type="text" name="nom7" placeholder="Last Name LF" required> 
			&nbsp;
			<input type="text" name="prenom7" placeholder="First Name LF" required> 
			&nbsp;
			<input type="number" name="age7" placeholder="LF Age" min=18 required>
			&nbsp;
			<input type="number" name="num7" placeholder="LF Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB7" placeholder="LF AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG7" placeholder="LF AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR7" placeholder="LF HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI7" placeholder="LF RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB7" placeholder="LF SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS7" placeholder="LF OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation CF -->
		
			Center Field : &nbsp;
			<input type="text" name="nom8" placeholder="Last Name CF" required> 
			&nbsp;
			<input type="text" name="prenom8" placeholder="First Name CF" required> 
			&nbsp;
			<input type="number" name="age8" placeholder="CF Age" min=18 required>
			&nbsp;
			<input type="number" name="num8" placeholder="CF Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB8" placeholder="CF AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG8" placeholder="CF AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR8" placeholder="CF HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI8" placeholder="CF RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB8" placeholder="CF SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS8" placeholder="CF OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><hr><br><br> <!-- Creation RF -->
		
			Right Field : &nbsp;
			<input type="text" name="nom9" placeholder="Last Name RF" required> 
			&nbsp;
			<input type="text" name="prenom9" placeholder="First Name RF" required> 
			&nbsp;
			<input type="number" name="age9" placeholder="RF Age" min=18 required>
			&nbsp;
			<input type="number" name="num9" placeholder="RF Numero" min=1 max=99 required>
			&nbsp;
			<br><br>
			<input type="number" name="AB9" placeholder="RF AB" min=0 required>
			&nbsp;
			<input type="number" name="AVG9" placeholder="RF AVG" min=0 max=1 step="0.001" required>
			&nbsp;
			<input type="number" name="HR9" placeholder="RF HR" min=0 required>
			&nbsp;
			<input type="number" name="RBI9" placeholder="RF RBI" min=0 required>
			&nbsp;
			<input type="number" name="SB9" placeholder="RF SB" min=0 required>
			&nbsp;
			<input type="number" name="OPS9" placeholder="RF OPS" min=0 max=2 step="0.001" required>
			&nbsp;
			<br><br><br><br>
			<input value="Abandon" type="reset">
			<input value="Validation" type="submit">
		</form>	
	</body> 

</html> 
