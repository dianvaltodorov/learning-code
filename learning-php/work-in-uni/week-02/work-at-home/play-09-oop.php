<!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php

      class Student{
        public $var = "a default value";
        public function displayVar(){
          echo $this->var;
        }
      }
      $studentInstance = new Student();


      class SimpleClass{
        public $var = "a default value";
        public function displayVar(){
          echo $this->var;
        }
      }


      $instance = new SimpleClass();
      echo var_dump($instance);
      echo "<br>";
      echo var_dump($instance->var);
      echo "<br>";
      $instance->displayVar();
      echo "<br>";

      $instance1 = new SimpleClass();
      echo var_dump($instance1);


      class MyClass{
        public $publicField = 'Public Foo';
        protected $protectedField = 'Protected Roo';
        private $privateField = 'Private Jae';

        function printHello(){
          echo $this->publicField;
          echo "<br>";
          echo $this->protectedField;
          echo "<br>";
          echo $this->privateField;
          echo "<br>";
        }
      }
      echo "<br>";
      $item = new MyClass;
      $item->printHello();

      $obj = new MyClass();
      echo $obj->publicField; // Works
      echo $obj->protectedField; // Fatal Error
      echo $obj->privateField; // Fatal Error
      $obj->printHello(); // Shows Public, Protected and Private

      class ExtendClass extends SimpleClass
      {
        // Redefine the parent method
         function displayVar() {
             echo "Extending class\n";
             parent::displayVar();
       }
      }
      $extended = new ExtendClass();
      $extended->displayVar();

      class Person {
         private $first_name;
         private $last_name;
         function __construct($first_name, $last_name) {
            $this->first_name = $first_name;
            $this->last_name = $last_name;
         }
         public function getFullName() {
            return $this->first_name.' '.$this->last_name;
         }
     }
     $person = new Person('Ivan', 'Ivanov');
     echo $person->getFullName();
    ?>
  </body>
</html>
