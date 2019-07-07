<?php
  $remote_addr = $_SERVER["REMOTE_ADDR"];
  if (strpos($remote_addr,'100.127.') !== false){
    $via_string = "SORACOM Napter";
    $via_class = "info";
    $via_description = "You connect remotely and securely.";
  } else {
    $via_string = "LAN";
    $via_class = "dark";
    $via_description = "Your remote address is in range of private addresses.";
  }
?>
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>SORACOM Napter Hands-on sample</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    <link href="cover.css" rel="stylesheet">
  </head>

  <body class="text-center bg-<?php echo $via_class ?>">

    <div class="cover-container d-flex w-100 h-100 p-3 mx-auto flex-column">
      <header class="masthead mb-auto"></header>
      <main role="main" class="inner cover">
        <h1 class="cover-heading">SORACOM Napter Hands-on sample</h1>
        <p class="lead">
          You are accessing here via&nbsp;&nbsp;
	  <button type="button" class="btn btn-white" data-toggle="popover" data-placement="bottom" data-content="<?php echo $via_description ?>"><?php echo $via_string ?></button>
          .
        </p>
      </main>

      <footer class="mastfoot mt-auto">
        <div class="inner">
          <p>Cover template for <a href="https://getbootstrap.com/">Bootstrap</a>, by <a href="https://twitter.com/mdo">@mdo</a>.</p>
        </div>
      </footer>
    </div>

    <!-- Bootstrap core JavaScript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
    <script type="text/javascript">
$(function () {
  $('[data-toggle="popover"]').popover()
})
    </script>
  </body>
</html>