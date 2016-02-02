* Защо долния код извежда само една единица?

echo $a === $b;
echo $a === $c;
echo $b === $c;


 * Защо като подкарам този код ми извежда
haz
haz
haz
haz

$arr = array('foo' => "bar", "joo" => "haz");
$nums = array(1,2,3,4);

foreach ($arr as $key => $value) {
   echo "$key => $value";
   echo "<br>";
}

echo "<br>";
foreach ($nums as $key) {
   echo $value."\n";
   echo "<br>";
}
echo "<br>";
