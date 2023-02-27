<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>

    <form id="f1"  enctype="multipart/form-data" action="script.php" method="post">
        <p>First Name <input type="text" name="firstName" required> </p>  
        <p>Last Name <input type="text" name="lastName" required> </p>
        <p>Email <input type="text" name="email" required> </p>
        <p>Address <textarea name="address" required></textarea> </p>
        <p>Photo <input type="file" name="photo" accept="image/*" required> </p>
        <p>Submit <input type="submit"> </p>
        <p>Clear <input type="reset"> </p>
    </form>
</body>
</html>
