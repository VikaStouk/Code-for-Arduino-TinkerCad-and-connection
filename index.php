<?php
$input = $_GET['xx'];

$sock = socket_create(AF_INET, SOCK_DGRAM, 0);
socket_sendto($sock, $input , strlen($input) , 0 , "127.0.0.1" , 15000);
?>