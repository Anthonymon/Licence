-- phpMyAdmin SQL Dump
-- version 4.6.6deb5
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Mer 17 Janvier 2018 à 15:21
-- Version du serveur :  10.1.24-MariaDB-6
-- Version de PHP :  7.0.22-3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `user`
--

-- --------------------------------------------------------

--
-- Structure de la table `aime`
--

CREATE TABLE `aime` (
  `identificateur_aime` varchar(12) NOT NULL,
  `ville` varchar(20) DEFAULT NULL,
  `pseudo` varchar(12) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `aime`
--

INSERT INTO `aime` (`identificateur_aime`, `ville`, `pseudo`) VALUES
('acch', 'Chicago', 'Acheridge'),
('acla', 'Los Angeles', 'Acheridge'),
('acsl', 'St. Louis', 'Acheridge'),
('acto', 'Toronto', 'Acheridge'),
('blba', 'Baltimore', 'Blushridge'),
('blcl', 'Cleveland', 'Blush'),
('blto', 'Toronto', 'Blushridge'),
('bobo', 'Boston', 'Boast'),
('bosf', 'San Francisco', 'Boast'),
('boto', 'Toronto', 'Boast'),
('coba', 'Baltimore', 'Corn'),
('cobo', 'Boston', 'Cornfull'),
('cola', 'Los Angeles', 'Cornfull'),
('cony', 'New York', 'Cornfull'),
('corla', 'Los Angeles', 'Corn'),
('diba', 'Baltimore', 'Direyard'),
('disf', 'San Francisco', 'Diregernon'),
('dwbo', 'Boston', 'Dwarfman'),
('dwcl', 'Cleveland', 'Dword'),
('dwla', 'Los Angeles', 'Dword'),
('dwsf', 'San Francisco', 'Dword'),
('faba', 'Baltimore', 'Faybald'),
('fabay', 'Baltimore', 'Faynath'),
('fabo', 'Boston', 'Faybald'),
('fach', 'Chicago', 'Faynath'),
('fala', 'Los Angeles', 'Faybald'),
('fany', 'New York', 'Faynath'),
('fasf', 'San Francisco', 'Faybald'),
('fecl', 'Cleveland', 'Fellred'),
('feny', 'New York', 'Fellred'),
('fesf', 'San Francisco', 'Fellred'),
('gala', 'Los Angeles', 'Gardmund'),
('giny', 'New York', 'Girth'),
('gocl', 'Cleveland', 'Goadriel'),
('gony', 'New York', 'Goadriel'),
('grba', 'Baltimore', 'Groanstone'),
('grcl', 'Cleveland', 'Groanstone'),
('grsf', 'San Francisco', 'Groanstone'),
('hach', 'Chicago', 'Haught'),
('hobo', 'Boston', 'Howard'),
('hocbo', 'Boston', 'Hocktor'),
('hocl', 'Cleveland', 'Horngurd'),
('hocto', 'Toronto', 'Hocktor'),
('horbo', 'Boston', 'Horngurd'),
('hoto', 'Toronto', 'Howard'),
('leba', 'Baltimore', 'Lewdfried'),
('lebo', 'Boston', 'Lewdfried'),
('lela', 'Los Angeles', 'Lewdfried'),
('leny', 'New York', 'Leafnath'),
('leto', 'Toronto', 'Lewdfried'),
('lobo', 'Boston', 'Lousefred'),
('locl', 'Cleveland', 'Lousefred'),
('lony', 'New York', 'Lousefred'),
('many', 'New York', 'Marswald'),
('masf', 'San Francisco', 'Marswald'),
('masl', 'St. Louis', 'Marswald'),
('mato', 'Toronto', 'Marswald'),
('mula', 'Los Angeles', 'Muff'),
('muto', 'Toronto', 'Muff'),
('nusl', 'St. Louis', 'Numl'),
('odny', 'New York', 'Oddsteen'),
('odsl', 'St. Louis', 'Oddsteen'),
('rebo', 'Boston', 'Redthon'),
('redbo', 'Boston', 'Redmur'),
('reny', 'New York', 'Redmur'),
('resl', 'St. Louis', 'Redthon'),
('runy', 'New York', 'Rudrence'),
('ruto', 'Toronto', 'Rudrence'),
('sksl', 'St. Louis', 'Skylard'),
('slcl', 'Cleveland', 'Slugill'),
('slny', 'New York', 'Slugill'),
('swch', 'Chicago', 'Swarmas'),
('toba', 'Baltimore', 'Tortvan'),
('tony', 'New York', 'Tortvan'),
('tosl', 'St. Louis', 'Tortvan'),
('twba', 'Baltimore', 'Twitley'),
('twch', 'Chicago', 'Twitley'),
('twny', 'New York', 'Twitley'),
('vabo', 'Boston', 'Vainreth'),
('vasf', 'San Francisco', 'Vainreth'),
('wach', 'Chicago', 'Warbert'),
('wasf', 'San Francisco', 'Warbert'),
('wasl', 'St. Louis', 'Warbert'),
('wato', 'Toronto', 'Warbert'),
('wibo', 'Boston', 'Wigto'),
('wich', 'Chicago', 'Wigto'),
('wicl', 'Cleveland', 'Wigto'),
('yisl', 'St. Louis', 'Yipney');

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Classement_playoff`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Classement_playoff` (
`PT` decimal(34,0)
,`ville` varchar(20)
,`league` enum('american','national')
);

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Classement_poules`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Classement_poules` (
`PT` decimal(34,0)
,`ville` varchar(20)
,`league` enum('american','national')
);

-- --------------------------------------------------------

--
-- Structure de la table `entraineur`
--

CREATE TABLE `entraineur` (
  `nom_entraineur` varchar(12) NOT NULL,
  `prenom_entraineur` varchar(12) NOT NULL,
  `annees_carriere` smallint(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `entraineur`
--

INSERT INTO `entraineur` (`nom_entraineur`, `prenom_entraineur`, `annees_carriere`) VALUES
('Bochy', 'Bruce', 4),
('Cockrell', 'Alan', 7),
('Cora', 'Alex', 6),
('Francona', 'Terry', 8),
('Gibbons', 'John', 3),
('Maddon', 'Joe', 3),
('Matheny', 'Mike', 8),
('Mattingly', 'Don', 3),
('Roberts', 'Dave', 6),
('Showalter', 'Buck', 5);

-- --------------------------------------------------------

--
-- Structure de la table `equipe`
--

CREATE TABLE `equipe` (
  `ville` varchar(20) NOT NULL,
  `nom` varchar(12) DEFAULT NULL,
  `league` enum('american','national') DEFAULT 'american',
  `nom_entraineur` varchar(12) DEFAULT NULL,
  `prenom_entraineur` varchar(12) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `equipe`
--

INSERT INTO `equipe` (`ville`, `nom`, `league`, `nom_entraineur`, `prenom_entraineur`) VALUES
('Baltimore', 'Orioles', 'american', 'Showalter', 'Buck'),
('Boston', 'Red Sox', 'american', 'Cora', 'Alex'),
('Chicago', 'Cubs', 'national', 'Maddon', 'Joe'),
('Cleveland', 'Indians', 'american', 'Francona', 'Terry'),
('Los Angeles', 'Dodgers', 'national', 'Roberts', 'Dave'),
('Miami', 'Marlins', 'national', 'Mattingly', 'Don'),
('New York', 'Yankees', 'american', 'Cockrell', 'Alan'),
('San Francisco', 'Giants', 'national', 'Bochy', 'Bruce'),
('St. Louis', 'Cardinals', 'national', 'Matheny', 'Mike'),
('Toronto', 'Blue Jays', 'american', 'Gibbons', 'John');

-- --------------------------------------------------------

--
-- Structure de la table `fan`
--

CREATE TABLE `fan` (
  `pseudo` varchar(12) NOT NULL,
  `nom_fan` varchar(12) NOT NULL,
  `prenom_fan` varchar(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `fan`
--

INSERT INTO `fan` (`pseudo`, `nom_fan`, `prenom_fan`) VALUES
('Acheridge', 'Stumb', 'Paulette'),
('Blush', 'Oxford', 'Robert'),
('Blushridge', 'Selig', 'Danny'),
('Boast', 'Martinez', 'Leta'),
('Corn', 'Corona', 'Jewell'),
('Cornfull', 'Kopp', 'Bettie'),
('Diregernon', 'Garcia', 'Douglas'),
('Direyard', 'Johnson', 'Jason'),
('Dwarfman', 'Roly', 'Robert'),
('Dword', 'Wright', 'Laura'),
('Faybald', 'Jenkins', 'Wayne'),
('Faynath', 'Gochenour', 'Nancy'),
('Fellred', 'Owen', 'Barbara'),
('Gardmund', 'Ong', 'Nathan'),
('Girth', 'Caron', 'Dennis'),
('Goadriel', 'Benitz', 'David'),
('Groanstone', 'Fenimore', 'Richard'),
('Haught', 'Stewart', 'Russel'),
('Hocktor', 'Pruitt', 'Ronald'),
('Horngurd', 'Cheeks', 'Ryan'),
('Howard', 'Nash', 'Sue'),
('Leafnath', 'Warney', 'Clifford'),
('Lewdfried', 'Harrington', 'Todd'),
('Lousefred', 'Pinnix', 'Thomas'),
('Marswald', 'Gorham', 'Nellie'),
('Muff', 'Holton', 'Andrew'),
('Numl', 'Cathcart', 'Kandace'),
('Oddsteen', 'Mitchell', 'Michael'),
('Redmur', 'White', 'Jeffery'),
('Redthon', 'York', 'Christopher'),
('Rudrence', 'Eck', 'Carl'),
('Skylard', 'Jordan', 'Kevin'),
('Slugill', 'White', 'Conrad'),
('Swarmas', 'Nelson', 'Gustavo'),
('Tortvan', 'Castana', 'Christopher'),
('Twitley', 'Bauer', 'Randy'),
('Vainreth', 'Pike', 'Keith'),
('Warbert', 'Sells', 'Craig'),
('Wigto', 'Jones', 'Sharon'),
('Yipney', 'Reedy', 'Rose');

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Infos_joueurs`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Infos_joueurs` (
`nom_joueur` varchar(12)
,`prenom_joueur` varchar(12)
,`numero` decimal(3,0)
,`poste` enum('P','C','1B','2B','3B','SS','LF','CF','RF')
,`age` decimal(3,0)
,`AB` int(4)
,`AVG` float
,`HR` int(4)
,`RBI` int(4)
,`SB` int(4)
,`OPS` float
,`ville` varchar(20)
);

-- --------------------------------------------------------

--
-- Structure de la table `joueur`
--

CREATE TABLE `joueur` (
  `nom_joueur` varchar(12) NOT NULL,
  `prenom_joueur` varchar(12) NOT NULL,
  `numero` decimal(3,0) DEFAULT NULL,
  `poste` enum('P','C','1B','2B','3B','SS','LF','CF','RF') DEFAULT 'RF',
  `age` decimal(3,0) DEFAULT NULL,
  `identificateur_stats` varchar(5) DEFAULT NULL,
  `ville` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `joueur`
--

INSERT INTO `joueur` (`nom_joueur`, `prenom_joueur`, `numero`, `poste`, `age`, `identificateur_stats`, `ville`) VALUES
('Allen', 'Cody', '37', 'P', '28', 'CL37', 'Cleveland'),
('Allene', 'Greg', '53', 'CF', '24', 'CL53', 'Cleveland'),
('Almonte', 'Abraham', '35', 'RF', '28', 'CL35', 'Cleveland'),
('Anderson', 'Brett', '46', 'P', '29', 'TO46', 'Toronto'),
('Anderson', 'Brian', '55', '3B', '24', 'Mi55', 'Miami'),
('Asher', 'Alec', '51', 'P', '26', 'BT51', 'Baltimore'),
('Bader', 'Harrison', '48', 'CF', '23', 'SL48', 'St. Louis'),
('Barnes', 'Austin', '15', 'C', '27', 'LA15', 'Los Angeles'),
('Bautista', 'Jose', '19', 'RF', '37', 'TO19', 'Toronto'),
('Beckham', 'Tim', '1', 'SS', '27', 'BT01', 'Baltimore'),
('Bellinger', 'Cody', '35', '1B', '22', 'LA35', 'Los Angeles'),
('Benintendi', 'Andrew', '16', 'LF', '23', 'BO16', 'Boston'),
('Berney', 'Darwin', '18', '2B', '31', 'TO18', 'Toronto'),
('Betances', 'Dellin', '68', 'P', '29', 'NY68', 'New York'),
('Betts', 'Mookie', '50', 'RF', '25', 'BO50', 'Boston'),
('Bird', 'Greg', '33', '1B', '24', 'NY33', 'New York'),
('Bogaerts', 'Xander', '2', 'SS', '25', 'BO02', 'Boston'),
('Bour', 'Justin', '41', '1B', '29', 'Mi41', 'Miami'),
('Brantley', 'Michael', '23', 'LF', '30', 'CL23', 'Cleveland'),
('Bryant', 'Kris', '17', '3B', '25', 'CH17', 'Chicago'),
('Bumgarner', 'Madison', '40', 'P', '28', 'SF40', 'San Francisco'),
('Carpenter', 'Matt', '13', '1B', '31', 'SL13', 'St. Louis'),
('Castillo', 'Wellington', '29', 'C', '30', 'BT29', 'Baltimore'),
('Castro', 'Starlin', '14', '2B', '27', 'NY14', 'New York'),
('Conley', 'Adam', '61', 'P', '27', 'Mi61', 'Miami'),
('Contreras', 'Willson', '40', 'C', '25', 'CH40', 'Chicago'),
('Cooper', 'Garrett', '12', '2B', '27', 'Mi12', 'Miami'),
('Crawford', 'Brandon', '35', 'SS', '30', 'SF35', 'San Francisco'),
('Culberson', 'Charlie', '37', 'SS', '28', 'LA37', 'Los Angeles'),
('Darvish', 'Yu', '21', 'P', '31', 'LA21', 'Los Angeles'),
('Davis', 'Chris', '19', '1B', '31', 'BT19', 'Baltimore'),
('Davis', 'Rajai', '25', 'CF', '37', 'BO25', 'Boston'),
('DeJong', 'Paul', '11', 'SS', '24', 'SL11', 'St. Louis'),
('Devers', 'Rafael', '11', '3B', '21', 'BO11', 'Boston'),
('Diaz', 'Yandy', '36', '3B', '26', 'CL36', 'Cleveland'),
('Donaldson', 'Josh', '20', '3B', '31', 'TO20', 'Toronto'),
('Ellsbury', 'Jacoby', '22', 'CF', '34', 'NY22', 'New York'),
('Fister', 'Doug', '38', 'P', '33', 'BO38', 'Boston'),
('Flaherty', 'Ryan', '3', '2B', '31', 'BT03', 'Baltimore'),
('Garcia', 'Greg', '35', '3B', '28', 'SL35', 'St. Louis'),
('Gardner', 'Bett', '11', 'LF', '34', 'NY11', 'New York'),
('Gentry', 'Craig', '14', 'LF', '33', 'BT14', 'Baltimore'),
('Gergorius', 'Didi', '18', 'SS', '27', 'NY18', 'New York'),
('Goins', 'Ryan', '17', 'SS', '29', 'TO17', 'Toronto'),
('Gomes', 'Yan', '7', 'C', '30', 'CL07', 'Cleveland'),
('Grichuk', 'Randal', '15', 'LF', '26', 'SL15', 'St. Louis'),
('Happ', 'Ian', '8', 'CF', '23', 'CH08', 'Chicago'),
('Hays', 'Austin', '18', 'CF', '22', 'BT18', 'Baltimore'),
('Headley', 'Chase', '12', '3B', '33', 'NY12', 'New York'),
('Hernandez', 'Enrique', '14', 'CF', '26', 'LA14', 'Los Angeles'),
('Heyward', 'Jason', '22', 'RF', '28', 'CH22', 'Chicago'),
('Holt', 'Brock', '12', '2B', '29', 'BO12', 'Boston'),
('Jones', 'Ryder', '22', '1B', '23', 'SF22', 'San Francisco'),
('Judge', 'Aaron', '99', 'RF', '25', 'NY99', 'New York'),
('Kipnis', 'Jason', '22', '2B', '30', 'CL22', 'Cleveland'),
('Lee', 'Braxton', '39', 'RF', '26', 'Mi39', 'Miami'),
('Leon', 'Sandy', '3', 'C', '28', 'BO03', 'Boston'),
('Lester', 'Jon', '34', 'P', '33', 'CH34', 'Chicago'),
('Lindor', 'Fracisco', '12', 'SS', '23', 'CL12', 'Cleveland'),
('Lopez', 'Raffy', '1', 'C', '30', 'TO01', 'Toronto'),
('Lynn', 'Lance', '31', 'P', '30', 'SL31', 'St. Louis'),
('Machado', 'Manny', '13', '3B', '25', 'BT13', 'Baltimore'),
('Mejia', 'Alex', '54', '2B', '26', 'SL54', 'St. Louis'),
('Molina', 'Yadier', '4', 'C', '35', 'SL04', 'St. Louis'),
('Moreland', 'Mitch', '18', '1B', '32', 'BO18', 'Boston'),
('Ozuna', 'Marcell', '13', 'LF', '27', 'Mi13', 'Miami'),
('Pearse', 'Steve', '28', 'LF', '34', 'TO28', 'Toronto'),
('Pence', 'Hunter', '8', 'RF', '34', 'SF08', 'San Francisco'),
('Pillar', 'Kevin', '11', 'CF', '28', 'TO11', 'Toronto'),
('Piscotty', 'Stephen', '55', 'RF', '26', 'SL55', 'St. Louis'),
('Posey', 'Buster', '28', 'C', '30', 'SF28', 'San Francisco'),
('Puig', 'Yasiel', '66', 'RF', '26', 'LA66', 'Los Angeles'),
('Realmuto', 'Jake', '11', 'C', '26', 'Mi11', 'Miami'),
('Rizzo', 'Anthony', '44', '1B', '28', 'CH44', 'Chicago'),
('Rojas', 'Miguel', '19', 'SS', '28', 'Mi19', 'Miami'),
('Romine', 'Austin', '27', 'C', '28', 'NY27', 'New York'),
('Russell', 'Addison', '27', 'SS', '23', 'CH27', 'Chicago'),
('Sandoval', 'Pablo', '48', '3B', '31', 'SF48', 'San Francisco'),
('Santana', 'Carlos', '41', '1B', '31', 'CL41', 'Cleveland'),
('Santander', 'Anthony', '25', 'RF', '23', 'BT25', 'Baltimore'),
('Schwarber', 'Kyle', '12', 'LF', '24', 'CH12', 'Chicago'),
('Slater', 'Austin', '53', 'LF', '24', 'SF53', 'San Francisco'),
('Smoak', 'Justin', '14', '1B', '30', 'TO14', 'Toronto'),
('Span', 'Denard', '2', 'CF', '33', 'SF02', 'San Francisco'),
('Taylor', 'Chris', '3', 'LF', '27', 'LA03', 'Los Angeles'),
('Tombinson', 'Kelby', '37', '2B', '27', 'SF37', 'San Francisco'),
('Turner', 'Justin', '10', '3B', '32', 'LA10', 'Los Angeles'),
('Utley', 'Chase', '26', '2B', '38', 'LA26', 'Los Angeles'),
('Yelich', 'Christian', '21', 'CF', '26', 'Mi21', 'Miami'),
('Zobrist', 'Ben', '18', '2B', '36', 'CH18', 'Chicago');

-- --------------------------------------------------------

--
-- Structure de la table `matchs`
--

CREATE TABLE `matchs` (
  `identificateur_match` varchar(10) NOT NULL,
  `date_match` varchar(10) DEFAULT NULL,
  `local_match` varchar(20) DEFAULT NULL,
  `visiteur_match` varchar(20) DEFAULT NULL,
  `ptl` int(3) DEFAULT NULL,
  `ptv` int(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `matchs`
--

INSERT INTO `matchs` (`identificateur_match`, `date_match`, `local_match`, `visiteur_match`, `ptl`, `ptv`) VALUES
('0109BTNY', '01/09/17', 'Baltimore', 'New York', 3, 6),
('0110BOTO', '01/10/17', 'Boston', 'Toronto', 1, 3),
('0209LASF', '02/09/17', 'Los Angeles', 'San Francisco', 5, 6),
('0309NYBT', '03/09/17', 'New York', 'Baltimore', 2, 0),
('0310BOCL', '03/10/17', 'Boston', 'Cleveland', 4, 0),
('0409SFLA', '04/09/17', 'San Francisco', 'Los Angeles', 1, 0),
('0410SLCH', '04/10/17', 'St. Louis', 'Chicago', 7, 4),
('0509CLNY', '05/09/17', 'Cleveland', 'New York', 2, 1),
('0510TOBO', '05/10/17', 'Toronto', 'Boston', 3, 1),
('0609CHSF', '06/09/17', 'Chicago', 'San Francisco', 3, 2),
('0709NYCL', '07/09/17', 'New York', 'Cleveland', 6, 2),
('0710CLTO', '07/10/17', 'Cleveland', 'Toronto', 0, 1),
('0809SFCH', '08/09/17', 'San Francisco', 'Chicago', 0, 2),
('0909BONY', '09/09/17', 'Boston', 'New York', 3, 8),
('0910TOCL', '09/10/17', 'Toronto', 'Cleveland', 5, 4),
('1009SLSF', '10/09/17', 'St. Louis', 'San Francisco', 1, 3),
('1109NYBO', '11/09/17', 'New York', 'Boston', 9, 3),
('1209SFSL', '12/09/17', 'San Francisco', 'St. Louis', 7, 3),
('1309TONY', '13/09/17', 'Toronto', 'New York', 2, 7),
('1509NYTO', '15/09/17', 'New York', 'Toronto', 4, 1),
('1709BTCL', '17/09/17', 'Baltimore', 'Cleveland', 6, 2),
('1809LACH', '18/09/17', 'Los Angeles', 'Chicago', 8, 6),
('1909BTBO', '19/09/17', 'Baltimore', 'Boston', 4, 5),
('2009LASL', '20/09/17', 'Los Angeles', 'St. Louis', 1, 5),
('2109BTTO', '21/09/17', 'Baltimore', 'Toronto', 3, 1),
('2309CLBT', '23/09/17', 'Cleveland', 'Baltimore', 8, 0),
('2409CHLA', '24/09/17', 'Chicago', 'Los Angeles', 2, 0),
('2509BOBT', '25/09/17', 'Boston', 'Baltimore', 5, 3),
('2609SLLA', '26/09/17', 'St. Louis', 'Los Angeles', 4, 5),
('2709TOBT', '27/09/17', 'Toronto', 'Baltimore', 1, 2),
('2909CLBO', '29/09/17', 'Cleveland', 'Boston', 0, 7),
('3009CHSL', '30/09/17', 'Chicago', 'St. Louis', 9, 0),
('PO1510NYSF', '15/10/17', 'New York', 'San Francisco', 4, 1),
('PO1610CHBO', '16/10/17', 'Chicago', 'Boston', 0, 2),
('PO1710SFNY', '17/10/17', 'San Francisco', 'New York', 2, 4),
('PO1810BOCH', '18/10/17', 'Boston', 'Chicago', 1, 0);

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Points_local_playoff`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Points_local_playoff` (
`ville` varchar(20)
,`pt_local` decimal(33,0)
);

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Points_local_poules`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Points_local_poules` (
`ville` varchar(20)
,`pt_local` decimal(33,0)
);

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Points_visiteur_playoff`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Points_visiteur_playoff` (
`ville` varchar(20)
,`pt_visiteur` decimal(33,0)
);

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `Points_visiteur_poules`
-- (Voir ci-dessous la vue réelle)
--
CREATE TABLE `Points_visiteur_poules` (
`ville` varchar(20)
,`pt_visiteur` decimal(33,0)
);

-- --------------------------------------------------------

--
-- Structure de la table `stats`
--

CREATE TABLE `stats` (
  `identificateur_stats` varchar(5) NOT NULL,
  `AB` int(4) DEFAULT NULL,
  `AVG_stats` float DEFAULT NULL,
  `HR` int(4) DEFAULT NULL,
  `RBI` int(4) DEFAULT NULL,
  `SB` int(4) DEFAULT NULL,
  `OPS` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `stats`
--

INSERT INTO `stats` (`identificateur_stats`, `AB`, `AVG_stats`, `HR`, `RBI`, `SB`, `OPS`) VALUES
('BO02', 571, 0.273, 10, 62, 15, 0.746),
('BO03', 271, 0.255, 7, 39, 0, 0.644),
('BO11', 222, 0.284, 10, 30, 3, 0.819),
('BO12', 140, 0.2, 0, 7, 2, 0.548),
('BO16', 573, 0.271, 20, 90, 20, 0.776),
('BO18', 508, 0.246, 22, 79, 0, 0.769),
('BO25', 336, 0.235, 5, 20, 29, 0.641),
('BO38', 324, 0.29, 5, 32, 7, 0.735),
('BO50', 628, 0.264, 24, 104, 26, 0.803),
('BT01', 533, 0.278, 22, 62, 6, 0.782),
('BT03', 622, 0.293, 32, 105, 1, 0.841),
('BT13', 630, 0.259, 33, 95, 9, 0.782),
('BT14', 101, 0.257, 2, 11, 5, 0.719),
('BT18', 60, 0.217, 1, 8, 0, 0.555),
('BT19', 456, 0.215, 26, 61, 1, 0.732),
('BT25', 330, 0.258, 13, 32, 2, 0.774),
('BT29', 341, 0.282, 20, 53, 0, 0.813),
('BT51', 254, 0.256, 8, 28, 0, 0.7),
('CH08', 364, 0.253, 24, 68, 8, 0.842),
('CH12', 422, 0.211, 30, 59, 1, 0.782),
('CH17', 549, 0.295, 29, 73, 7, 0.946),
('CH18', 435, 0.232, 12, 50, 2, 0.693),
('CH22', 432, 0.259, 11, 59, 4, 0.715),
('CH27', 352, 0.239, 12, 43, 2, 0.722),
('CH34', 311, 0.264, 14, 49, 0, 0.834),
('CH40', 377, 0.276, 21, 74, 5, 0.855),
('CH44', 572, 0.273, 32, 109, 10, 0.899),
('CL07', 341, 0.232, 14, 56, 0, 0.708),
('CL12', 651, 0.273, 33, 89, 15, 0.842),
('CL22', 336, 0.232, 12, 35, 6, 0.705),
('CL23', 338, 0.299, 9, 52, 11, 0.801),
('CL35', 172, 0.233, 3, 14, 2, 0.681),
('CL36', 156, 0.263, 0, 13, 2, 0.679),
('CL37', 554, 0.258, 38, 107, 2, 0.881),
('CL41', 571, 0.259, 23, 79, 5, 0.818),
('CL53', 555, 0.254, 36, 101, 1, 0.832),
('LA03', 514, 0.288, 21, 72, 17, 0.85),
('LA10', 457, 0.322, 21, 71, 7, 0.945),
('LA14', 297, 0.215, 11, 37, 3, 0.729),
('LA15', 218, 0.289, 8, 38, 4, 0.895),
('LA21', 438, 0.247, 22, 58, 0, 0.767),
('LA26', 309, 0.236, 8, 34, 6, 0.728),
('LA35', 480, 0.267, 39, 97, 10, 0.933),
('LA37', 539, 0.295, 22, 77, 4, 0.854),
('LA66', 499, 0.263, 28, 74, 15, 0.833),
('Mi11', 532, 0.278, 17, 65, 8, 0.783),
('Mi12', 443, 0.3, 16, 63, 2, 0.792),
('Mi13', 613, 0.312, 37, 124, 1, 0.924),
('Mi19', 272, 0.29, 1, 26, 2, 0.736),
('Mi21', 602, 0.282, 18, 81, 16, 0.807),
('Mi39', 228, 0.25, 3, 31, 0, 0.637),
('Mi41', 377, 0.289, 25, 83, 1, 0.902),
('Mi55', 84, 0.262, 0, 8, 0, 0.706),
('Mi61', 406, 0.249, 13, 53, 0, 0.758),
('NY11', 594, 0.264, 21, 63, 23, 0.778),
('NY12', 512, 0.273, 12, 61, 9, 0.758),
('NY14', 443, 0.3, 16, 63, 2, 0.792),
('NY18', 534, 0.287, 25, 87, 3, 0.796),
('NY22', 356, 0.264, 7, 39, 22, 0.75),
('NY27', 229, 0.218, 2, 21, 0, 0.565),
('NY33', 147, 0.19, 9, 28, 0, 0.71),
('NY68', 471, 0.278, 33, 90, 2, 0.876),
('NY99', 542, 0.284, 52, 114, 9, 1.049),
('SF02', 497, 0.272, 12, 43, 12, 0.756),
('SF08', 493, 0.26, 13, 67, 2, 0.701),
('SF22', 125, 0.192, 3, 14, 1, 0.548),
('SF28', 494, 0.32, 12, 67, 6, 0.861),
('SF35', 518, 0.253, 14, 77, 3, 0.709),
('SF37', 194, 0.258, 1, 11, 9, 0.646),
('SF40', 287, 0.244, 9, 35, 0, 0.691),
('SF48', 259, 0.22, 9, 32, 0, 0.632),
('SF53', 117, 0.282, 3, 16, 0, 0.74),
('SL04', 501, 0.273, 18, 82, 9, 0.751),
('SL11', 417, 0.285, 25, 65, 1, 0.857),
('SL13', 497, 0.241, 23, 69, 2, 0.835),
('SL15', 412, 0.238, 22, 59, 6, 0.758),
('SL31', 114, 0.246, 4, 18, 0, 0.736),
('SL35', 241, 0.253, 2, 20, 2, 0.697),
('SL48', 85, 0.235, 3, 10, 2, 0.659),
('SL54', 354, 0.285, 4, 42, 8, 0.788),
('SL55', 341, 0.235, 9, 39, 3, 0.708),
('TO01', 307, 0.221, 13, 35, 1, 0.731),
('TO11', 587, 0.256, 16, 42, 15, 0.704),
('TO14', 560, 0.27, 38, 90, 0, 0.883),
('TO17', 418, 0.237, 9, 62, 3, 0.643),
('TO18', 336, 0.232, 6, 25, 7, 0.602),
('TO19', 587, 0.203, 23, 65, 6, 0.674),
('TO20', 415, 0.27, 33, 78, 2, 0.944),
('TO28', 313, 0.252, 13, 37, 0, 0.757),
('TO46', 557, 0.25, 28, 85, 0, 0.753);

-- --------------------------------------------------------

--
-- Structure de la vue `Classement_playoff`
--
DROP TABLE IF EXISTS `Classement_playoff`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Classement_playoff`  AS  select (`Points_local_playoff`.`pt_local` + `Points_visiteur_playoff`.`pt_visiteur`) AS `PT`,`equipe`.`ville` AS `ville`,`equipe`.`league` AS `league` from ((`equipe` join `Points_local_playoff`) join `Points_visiteur_playoff`) where ((`equipe`.`ville` = `Points_local_playoff`.`ville`) and (`equipe`.`ville` = `Points_visiteur_playoff`.`ville`)) group by `equipe`.`ville` having (`PT` <> 0) order by (`Points_local_playoff`.`pt_local` + `Points_visiteur_playoff`.`pt_visiteur`) desc ;

-- --------------------------------------------------------

--
-- Structure de la vue `Classement_poules`
--
DROP TABLE IF EXISTS `Classement_poules`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Classement_poules`  AS  select (`Points_local_poules`.`pt_local` + `Points_visiteur_poules`.`pt_visiteur`) AS `PT`,`equipe`.`ville` AS `ville`,`equipe`.`league` AS `league` from ((`equipe` join `Points_local_poules`) join `Points_visiteur_poules`) where ((`equipe`.`ville` = `Points_local_poules`.`ville`) and (`equipe`.`ville` = `Points_visiteur_poules`.`ville`)) group by `equipe`.`ville` order by (`Points_local_poules`.`pt_local` + `Points_visiteur_poules`.`pt_visiteur`) desc ;

-- --------------------------------------------------------

--
-- Structure de la vue `Infos_joueurs`
--
DROP TABLE IF EXISTS `Infos_joueurs`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Infos_joueurs`  AS  select `joueur`.`nom_joueur` AS `nom_joueur`,`joueur`.`prenom_joueur` AS `prenom_joueur`,`joueur`.`numero` AS `numero`,`joueur`.`poste` AS `poste`,`joueur`.`age` AS `age`,`stats`.`AB` AS `AB`,`stats`.`AVG_stats` AS `AVG`,`stats`.`HR` AS `HR`,`stats`.`RBI` AS `RBI`,`stats`.`SB` AS `SB`,`stats`.`OPS` AS `OPS`,`equipe`.`ville` AS `ville` from ((`joueur` join `equipe`) join `stats`) where ((`joueur`.`ville` = `equipe`.`ville`) and (`joueur`.`identificateur_stats` = `stats`.`identificateur_stats`)) ;

-- --------------------------------------------------------

--
-- Structure de la vue `Points_local_playoff`
--
DROP TABLE IF EXISTS `Points_local_playoff`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Points_local_playoff`  AS  select `equipe`.`ville` AS `ville`,sum((`m2`.`ptl` - `m2`.`ptv`)) AS `pt_local` from (`equipe` join `matchs` `m2`) where ((`equipe`.`ville` = `m2`.`local_match`) and (`m2`.`identificateur_match` like 'PO%')) group by `equipe`.`ville` union select `equipe`.`ville` AS `ville`,0 AS `0` from `equipe` where (not(`equipe`.`ville` in (select distinct `equipe`.`ville` from (`equipe` join `matchs` `m3`) where ((`equipe`.`ville` = `m3`.`local_match`) and (`m3`.`identificateur_match` like 'PO%'))))) ;

-- --------------------------------------------------------

--
-- Structure de la vue `Points_local_poules`
--
DROP TABLE IF EXISTS `Points_local_poules`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Points_local_poules`  AS  select `equipe`.`ville` AS `ville`,sum((`m2`.`ptl` - `m2`.`ptv`)) AS `pt_local` from (`equipe` join `matchs` `m2`) where ((`equipe`.`ville` = `m2`.`local_match`) and (not((`m2`.`identificateur_match` like 'PO%')))) group by `equipe`.`ville` ;

-- --------------------------------------------------------

--
-- Structure de la vue `Points_visiteur_playoff`
--
DROP TABLE IF EXISTS `Points_visiteur_playoff`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Points_visiteur_playoff`  AS  select `equipe`.`ville` AS `ville`,sum((`m2`.`ptv` - `m2`.`ptl`)) AS `pt_visiteur` from (`equipe` join `matchs` `m2`) where ((`equipe`.`ville` = `m2`.`visiteur_match`) and (`m2`.`identificateur_match` like 'PO%')) group by `equipe`.`ville` union select `equipe`.`ville` AS `ville`,0 AS `0` from `equipe` where (not(`equipe`.`ville` in (select distinct `equipe`.`ville` from (`equipe` join `matchs` `m3`) where ((`equipe`.`ville` = `m3`.`visiteur_match`) and (`m3`.`identificateur_match` like 'PO%'))))) ;

-- --------------------------------------------------------

--
-- Structure de la vue `Points_visiteur_poules`
--
DROP TABLE IF EXISTS `Points_visiteur_poules`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root2`@`localhost` SQL SECURITY DEFINER VIEW `Points_visiteur_poules`  AS  select `equipe`.`ville` AS `ville`,sum((`m2`.`ptv` - `m2`.`ptl`)) AS `pt_visiteur` from (`equipe` join `matchs` `m2`) where ((`equipe`.`ville` = `m2`.`visiteur_match`) and (not((`m2`.`identificateur_match` like 'PO%')))) group by `equipe`.`ville` ;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `aime`
--
ALTER TABLE `aime`
  ADD PRIMARY KEY (`identificateur_aime`),
  ADD KEY `ville` (`ville`),
  ADD KEY `pseudo` (`pseudo`);

--
-- Index pour la table `entraineur`
--
ALTER TABLE `entraineur`
  ADD PRIMARY KEY (`nom_entraineur`,`prenom_entraineur`);

--
-- Index pour la table `equipe`
--
ALTER TABLE `equipe`
  ADD PRIMARY KEY (`ville`),
  ADD KEY `nom_entraineur` (`nom_entraineur`,`prenom_entraineur`);

--
-- Index pour la table `fan`
--
ALTER TABLE `fan`
  ADD PRIMARY KEY (`pseudo`);

--
-- Index pour la table `joueur`
--
ALTER TABLE `joueur`
  ADD PRIMARY KEY (`nom_joueur`,`prenom_joueur`),
  ADD KEY `identificateur_stats` (`identificateur_stats`),
  ADD KEY `ville` (`ville`);

--
-- Index pour la table `matchs`
--
ALTER TABLE `matchs`
  ADD PRIMARY KEY (`identificateur_match`),
  ADD KEY `local_match` (`local_match`),
  ADD KEY `visiteur_match` (`visiteur_match`);

--
-- Index pour la table `stats`
--
ALTER TABLE `stats`
  ADD PRIMARY KEY (`identificateur_stats`);

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `aime`
--
ALTER TABLE `aime`
  ADD CONSTRAINT `aime_ibfk_1` FOREIGN KEY (`ville`) REFERENCES `equipe` (`ville`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `aime_ibfk_2` FOREIGN KEY (`pseudo`) REFERENCES `fan` (`pseudo`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `equipe`
--
ALTER TABLE `equipe`
  ADD CONSTRAINT `equipe_ibfk_1` FOREIGN KEY (`nom_entraineur`,`prenom_entraineur`) REFERENCES `entraineur` (`nom_entraineur`, `prenom_entraineur`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `joueur`
--
ALTER TABLE `joueur`
  ADD CONSTRAINT `joueur_ibfk_1` FOREIGN KEY (`identificateur_stats`) REFERENCES `stats` (`identificateur_stats`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `joueur_ibfk_2` FOREIGN KEY (`ville`) REFERENCES `equipe` (`ville`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `matchs`
--
ALTER TABLE `matchs`
  ADD CONSTRAINT `matchs_ibfk_1` FOREIGN KEY (`local_match`) REFERENCES `equipe` (`ville`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `matchs_ibfk_2` FOREIGN KEY (`visiteur_match`) REFERENCES `equipe` (`ville`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
