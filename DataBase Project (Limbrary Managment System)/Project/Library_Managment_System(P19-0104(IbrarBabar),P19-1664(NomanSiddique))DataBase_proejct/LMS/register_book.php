<!DOCTYPE html>
<html>
<head>
	<title>LMS</title>
	<meta charset="utf-8" name="viewport" content="width=device-width,intial-scale=1">
	<link rel="stylesheet" type="text/css" href="bootstrap-4.4.1/css/bootstrap.min.css">
  	<script type="text/javascript" src="bootstrap-4.4.1/js/juqery_latest.js"></script>
  	<script type="text/javascript" src="bootstrap-4.4.1/js/bootstrap.min.js"></script>
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

<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<div class="container-fluid">
			<div class="navbar-header">
				<a class="navbar-brand" href="index.php">Library Management System(LMS)</a>
			</div>
			<ul class="nav navbar-nav navbar-right">

				<li class="nav-item"><a class="nav-link" href="logout.php">Logout</a></li>
			</ul>
		</div>
	</nav>
<div class="col-md-8" id="main_content">
			<center><h3>User Registration Form</h3></center>
			<form action="registerBOOK.php" method="post">
				<div class="form-group">
					<label for="name">Serial_No.</label>
					<input type="text" name="s_no" class="form-control" required>
				</div>
				<div class="form-group">
					<label for="name">BOOK Name</label>
					<input type="text" name="book_name" class="form-control" required>
				</div>
				<div class="form-group">
					<label for="name">Book Author</label>
					<input type="text" name="book_author" class="form-control" required>
				</div>
				<div class="form-group">
					<label for="name">Issue Date</label>
					<input type="text" name="issue_date" class="form-control" required>
				</div>
				<button type="submit" class="btn btn-primary">Register</button>
			</form>
	</div>
	</div>
	</body>
</html>