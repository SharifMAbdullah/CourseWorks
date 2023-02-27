<?php
    $f_name = $_POST['firstName'];
    $l_name = $_POST['lastName'];
    $email = $_POST['email'];
    $addr = $_POST['address'];
    $img = $_FILES['photo']['name'];
    $tmpimage = $_FILES['photo']['tmp_name'];
    $location = "./photos/" . $img;

    move_uploaded_file($tmpimage, $location);
    echo "Name: " . $f_name . " " . $l_name; echo "<br>";
    echo "Email: " . $email; echo "<br>";
    echo "Address: " . $addr; echo "<br>";
?>

<!DOCTYPE html>
<html lang="en">
<head>
</head>
<body>
    <div class="right-box">
        <img src="./photos/<?php echo $img; ?>" alt="image" width="50%" height="50%" style='border-radius: 50%; width: 10rem; min-height: 10rem;'>
    </div>
</body>
</html>