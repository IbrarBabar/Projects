<?php
	$connection = mysqli_connect("localhost","root","");
	$db = mysqli_select_db($connection,"library_managment_system");
	$query = "insert into issued_books values($_POST[s_no],'$_POST[book_name]','$_POST[book_author]',2,1,'$_POST[issue_date]',4)";
	$query_run = mysqli_query($connection,$query);
?>
<script type="text/javascript">
	alert("Registration successfully....You may login now.")
	window.location.href = "index.php";
</script>