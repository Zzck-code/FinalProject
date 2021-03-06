
<html>
  <head>
    <title> Automatic Irrigation System</title>
    <!-- <link type="text/css" href="css/bootstrap.min.css" rel="stylesheet"> -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    <!-- <link type="text/css" href="css/bootstrap-table.css" rel="stylesheet"> -->
    <link rel="stylesheet" href="https://unpkg.com/bootstrap-table@1.15.2/dist/bootstrap-table.min.css">
    <link type="text/css" href="css/font-awesome.css" rel="stylesheet">
    <meta http-equiv="refresh" content="15">
</head>
 
<body>

<div class="container">
  <div class="col-md-12">
    <div class="page-header" style="text-align: center;color:">
      <h1>
        Automatic Irrigation System
      </h1>
    </div>


    <div class="panel panel-success">
             
      <div class="panel-body">
        <div class="row">
          <div class="col-md-12">
           
            <table  id="table"
                        data-show-columns="true"
                        data-height="460">
            </table>

          </div>
        </div>
      </div>        
    </div>

  </div>
</div>
      
<script src="js/jquery-1.11.1.min.js"></script>
<!-- <script src="js/bootstrap.min.js"></script> -->
<!-- <script src="js/bootstrap-table.js"></script> -->
<script src="https://unpkg.com/bootstrap-table@1.15.2/dist/bootstrap-table.min.js"></script>


<script type="text/javascript">
  
   var $table = $('#table');
         $table.bootstrapTable({
            url: 'list-data.php',
            search: true,
            pagination: true,
            buttonsClass: 'none',
            showFooter: true,
            minimumCountColumns: 2,
            columns: [{
                field: 'num',
                title: 'no',
                sortable: true,
            },{
                field: 'humidity',
                title: 'Soil Moisture',
                // sortable: true,
            },{
                field: 'waterPump',
                title: 'Status Water Pump',
                // sortable: true,
                
            },{
                field: 'date',
                title: 'Date',
                // sortable: true,
            },{
                field: 'time',
                title: 'Time',
                // sortable: true,
            }  ],
 
         });

</script>

</body>
</html>





