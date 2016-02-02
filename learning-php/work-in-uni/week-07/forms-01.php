<!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php
    $titleErr = "";
    $title = "";

    $description = "";
    $descriptionErr = "";

    $lecturer = "";
    $lecturerErr = "";

    $type = "";
    $typeErr = "";

    $program = "";
    $programmErr = "";

    $course = "";
    $courseErr = "";

    $lecturer = "";
    $lecturerErr = "";

    $name = "";
    $nameErr = "";

    $lecturerEmail = "";
    $lecturerEmailErr = "";


    $materials = "";
    $materialsErr = "";


    function process_input($data) {
      $data = trim($data);
      $data = stripslashes($data);
      $data = htmlspecialchars($data);
      return $data;
    }


    function get_form_data($field_name, &$val, &$err)  {
       if ($_SERVER["REQUEST_METHOD"] == "POST") {
          if (empty($_POST[$field_name])) {
            $err = "Field is required";
          } else {
            $val = process_input($_POST[$field_name]);
          }
        }
    }

    get_form_data("title", $title, $titleErr);
    get_form_data("lecturer_name", $lecturer, $lecturerErr);
    get_form_data("description", $description, $descriptionErr);
    get_form_data("program", $program, $programErr);
    get_form_data("course", $course, $courseErr);
    get_form_data("type", $type, $typeErr);
    get_form_data("name", $name, $nameErr);
    get_form_data("lecturer_email",$lecturerEmail, $lecturerEmailErr);
    get_form_data("materials",$materials, $materialsErr);


    if (!(empty($lecturerEmail))){
        if(!ereg("^[A-Za-z0-9\.|-|_]*[@]{1}[A-Za-z0-9\.|-|_]*[.]{1}[a-z]{2,5}$", $lecturerEmail)){
          $lecturerEmailErr = "Invalid email format";
        }
    }


    if (!(empty($materials))){
      if(!ereg("^*.zip$", $materials)){
          $materialsErr = "File not zip.";
        }
    }
  
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Title:<input type="text" name="title">
              <span class="error">* <?php echo $titleErr;?></span>
              <br><br>
        <textarea name="description" rows=11 cols=50 maxlength=200 ></textarea>
        <span class="error">* <?php echo $descriptionErr;?></span>
        <br><br>
        Lecture Name: <input type="text" name="lecturer_name" maxlength="20">
        <span class="error">* <?php echo $lecturerErr;?></span>
        <br><br>
        Type: <input type="radio" name="type" value="elective"> elective
              <input type="radio" name="type" value="mandatory"> mandatory
              <span class="error">* <?php echo $typeErr;?></span>
              <br><br>
        Course: <select name="course">
                <option value="first" selected>First</option>
                <option value="second">Second</option>
                <option value="second">All</option>
                </select>
                <span class="error">* <?php echo $courseErr;?></span>
                <br><br>
        Program: <input type="checkbox" name="program" value="bachelor"> Bachelor
                 <input type="checkbox" name="program" value="master"> Master
                 <span class="error">* <?php echo $programErr;?></span>
                 <br><br>
         Add materials(zip format):<input type="file" name="materials">
                                   <span class="error">* <?php echo $materialsErr;?></span>
                                   <br><br>
         Lecturer Email: <input type="text" name="lecturer_email">
                         <span class="error">* <?php echo $lecturerEmailErr;?></span>
                         <br><br>
         Name  <input type="hidden" name="name">
               <span class="error">* <?php echo $nameErr;?></span>
               <br><br>
        <input type="submit">
    </form>

  </body>
</html>
