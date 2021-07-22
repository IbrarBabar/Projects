<html>
<head>
 <title>Student Information</title>
 <style type="text/css">
#side_bar{
background-color: whitesmoke;
padding: 50px;
width: 150px;
height: 150px;
}
</style>
 <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3
.1/css/bootstrap.min.css" integrity="sha384-
ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="an
onymous">
<style type="text/css">
  		#side_bar{
  			background-color: whitesmoke;
  			padding: 50px;
  			width: 300px;
  			height: 450px;
  		}
  	</style>
</head>
<body>

<?php 
if(isset($_POST['login'])){
 {
 $username = 'root';
 $password = '';
 // Check connection
 try {
 $conn = new PDO("mysql:host=localhost;dbname=library_managment_system", $username, $password);
 // set the PDO error mode to exception
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
 } catch(PDOException $e) {
 echo "Connection failed: " . $e->getMessage();
 }
 session_start();
   $roll= $_SESSION['email'];

 $query_1 = $conn->prepare(" select * from books join join_data using (book_id) join users using (id) where email != ?");
 $query_1->execute([$roll]);
 $result = $query_1->fetchAll(PDO::FETCH_ASSOC);


 ?>	
 <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<div class="container-fluid">
			<div class="navbar-header">
				<a class="navbar-brand" href="index.php">Library Management System(LMS)</a>
			</div>
			<ul class="nav navbar-nav navbar-right">

				<li class="nav-item"><a class="nav-link" href="logout.php">Logout</a></li>
			</ul>
		</div>
	</nav><br>

 </thead>
 <tbody>
 <center><h4>Available Books</h4></center>
 <tbody>
 <div class="row">
	<div class="col-md-2"></div>
	<div class="col-md-8">
		<form>
			<table class="table-bordered" width="900px" style="text-align: center">
				<tr>
					<th>Book ID</th>	
					<th>Book Name</th>
					<th>Author ID</th>
					
				</tr>
				
				<?php
					foreach ($result as $key=>$value){
						
						$Book_name = "";
						$author_id = "";
						$book_id="";
						$book_id=$value['book_id'];
						$Book_name = $value['book_name'];
						$author_id = $value['author_id'];
						
				?>
				
						<tr>
							<td><?php echo $book_id;?></td>
							<td><?php echo $Book_name;?></td>
							<td><?php echo $author_id;?></td>
							</form>
						</tr>				
						<?php
					}
				?>
			</table>
		</form>
	</div>
	<div class="col-md-2"></div>
</div>

<br><br>
			<center><h4>For Register Book click the Botton</h4></center><br>
			<form action="register_book.php" method="post">
			<center>	<button type="submit" class="btn btn-primary">Register Avaialbe Books</button></center>
			</form>
	</div>
	</div>
 </tbody>
 </table>
 <?php
}
}
else{
	?>
	<br><br><center><span class="alert-danger">Wrong Password</span></center>
	<?php
}
?>
</body>
</html>