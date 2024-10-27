<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multiplication Table</title>
    <style>
        table {
            border-collapse: collapse;
            margin: 20px 0;
        }
        table, th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }
    </style>
</head>
<body>

    <h2>Multiplication Table Generator</h2>
    <form method="post" action="">
        <label for="number">Enter a number:</label>
        <input type="number" id="number" name="number" required>
        <input type="submit" value="Generate Table">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Get the number from the form
        $number = intval($_POST['number']);

        // Validate the number
        if ($number > 0) {
            // Display the multiplication table
            echo "<h3>Multiplication Table up to $number</h3>";
            echo "<table>";
            
            // Print the header row
            echo "<tr><th>x</th>";
            for ($i = 1; $i <= $number; $i++) {
                echo "<th>$i</th>";
            }
            echo "</tr>";

            // Print the table rows
            for ($i = 1; $i <= $number; $i++) {
                echo "<tr>";
                echo "<th>$i</th>"; // Row index
                for ($j = 1; $j <= $number; $j++) {
                    echo "<td>" . ($i * $j) . "</td>"; // Multiplication result
                }
                echo "</tr>";
            }

            echo "</table>";
        } else {
            echo "<p>Please enter a positive integer.</p>";
        }
    }
    ?>

</body>
</html>