<?php
class Grid {
    function __construct(){
        //Attempting to make the output have line breaks in both windows and terminal
        if ($_SERVER['SERVER_NAME'] == ""){
            $this -> breakVar = "\n";
        }
        else{
            $this -> breakVar = "<br>";
        }
        for ($i = 0; $i < 81; $i ++){
            $row = $i/9;
            $col = $i%9;
            $this -> playerGrid[$row][$col] = 0;
        }
    }

    function resetGrid()
    {
        for ($i = 0; $i < 81; $i ++){
            $row = $i/9;
            $col = $i%9;
            $this -> playerGrid[$row][$col] = 0;
        }
    }

    function readGrid(){
        echo $this -> breakVar."-------------".$this -> breakVar;
        for ($i = 0; $i < 9; $i ++){
            for ($x = 0; $x < 9; $x ++){
                if($x == 0){
                    echo "|";
                }
                echo $this -> playerGrid[$i][$x];
                if ($x > 0 && ($x+1) % 3 == 0){
                    echo "|";
                }
            }
            echo $this -> breakVar;
            if ($i > 0 && ($i+1) % 3 == 0){
                echo "-------------".$this -> breakVar;
            }
        }
    }

    function solveGrid(){
        $possibles = array();
        for ($x = 0; $x < 81; $x++) {
            $tempRow = $x / 9;
            $tempCol = $x % 9;
            if ($this -> playerGrid[$tempRow][$tempCol] == 0) {
                $colValues = array ();
                $rowValues = array();
                for ($y = 0; $y < 9; $y++) 
                {
                    array_push($colValues, $this -> playerGrid[$tempRow][$y]);
                    array_push($rowValues, $this -> playerGrid[$y][$tempCol]);
                    array_push($possibles, $y + 1);
                }
                shuffle($possibles);
                foreach ($possibles as $value) {
                    $foundCol = array_search($value, $colValues);
                    if ($foundCol == "") {
                        $foundRow = array_search($value, $rowValues);
                        if ($foundRow == "") {
                            if ($tempRow < 3) {
                                if ($tempCol < 3) {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow][$squaCol];
                                    }
                                }
                                else if ($tempCol < 6) {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow][$squaCol + 3];
                                    }
                                }
                                else {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow][$squaCol + 6];
                                    }
                                }
                            }
                            else if ($tempRow < 6) {
                                if ($tempCol < 3) {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow + 3][$squaCol];
                                    }
                                }
                                else if ($tempCol < 6) {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow + 3][$squaCol + 3];
                                    }
                                }
                                else {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow + 3][$squaCol + 6];
                                    }
                                }
                            }
                            else {
                                if ($tempCol < 3) {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow + 6][$squaCol];
                                    }
                                }
                                else if ($tempCol < 6) {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow + 6][$squaCol + 3];
                                    }
                                }
                                else {
                                    for ($z = 0; $z < 9; $z++) {
                                        $squaRow = $z / 3;
                                        $squaCol = $z % 3;
                                        $square[$squaRow][$squaCol] = $this -> playerGrid[$squaRow + 6][$squaCol + 6];
                                    }
                                }
                            }
                            $gridValues = array();
                            for ($z = 0; $z < 3; $z++) {
                                for ($h = 0; $h < 3; $h++) {
                                    array_push($gridValues, $square[$h][$z]);
                                }
                            }
                            $found = array_search($value, $gridValues);
                            if ($found == "") {
                                $this -> playerGrid[$tempRow][$tempCol] = $value;
                                if ($this->checkGrid()) {
                                    return true;
                                }
                                else {
                                    if ($this->solveGrid()) {
                                        return true;
                                    }
                                }
                            }
                        }
                        else{
                        }
                    }
                    else{
                    }
                }
                return false;
            }
        }
    }

    function checkGrid(){
        for ($x = 0; $x < 9; $x++) {
            for ($y = 0; $y < 9; $y++) {
                if ($this -> playerGrid[$x][$y] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    private $playerGrid;
    private $breakVar;
}
echo "Loading grid...";
$test = new Grid();
$solved = $test->solveGrid();
while($solved != true){
    $test -> resetGrid();
    $solved = $test -> solveGrid();
}
$test -> readGrid();
?>