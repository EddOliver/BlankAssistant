<?php
$file = fopen('myCSVFile.csv', 'r');
while (($line = fgetcsv($file)) !== FALSE) {
  //$line is an array of the csv elements
  print_r($line);
}
fclose($file);
?>
