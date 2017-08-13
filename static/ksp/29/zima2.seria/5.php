<?php

$file= fopen("data.txt", "r");

$data=fread($file, 1000000000);
$data=strip_tags($data);
echo $data;


?>
