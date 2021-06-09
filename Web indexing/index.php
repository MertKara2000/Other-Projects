<!DOCTYPE html>
<html lang="tr">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>WEB İNDEXLEME UYGULAMASI</title>
  <link rel="stylesheet" href="content/css/style.css">
</head>
<?php
if($_POST){
    if(isset($_POST['hesapla'])){
        $url=$_POST['hesapla'];
$dosya=fopen('url.txt','w');
$ekle=fwrite($dosya,$url);
fclose($dosya);
putenv('LANG=tr_TR.UTF-8');
$command = escapeshellcmd('python3 odev1_b.py');
$output = shell_exec($command);
}
    if(isset($_POST['kelime'])){
        $url=$_POST['kelime'];
$dosya=fopen('url.txt','w');
$ekle=fwrite($dosya,$url);
fclose($dosya);
putenv('LANG=tr_TR.UTF-8');
$command = escapeshellcmd('python3 odev2_b.py');
$output = shell_exec($command);
    }
    if(isset($_POST['skora'])&&isset($_POST['skorb'])){
        $url=$_POST['skora'];
        $urltwo=$_POST['skorb'];
        
$dosya=fopen('url.txt','w');
$ekle=fwrite($dosya,$url);
fclose($dosya);
$dosyatwo=fopen('url2.txt','w');
$ekle=fwrite($dosyatwo,$urltwo);
fclose($dosyatwo);
putenv('LANG=tr_TR.UTF-8');
$command = escapeshellcmd('python3 odev3_b.py');
$output = shell_exec($command);
    }
    if(isset($_POST['indexle'])&&isset($_POST['sirala'])){
         $url=$_POST['indexle'];
        $urltwo=$_POST['sirala'];
        
$dosya=fopen('url.txt','w');
$ekle=fwrite($dosya,$url);
fclose($dosya);
$dosyatwo=fopen('url2.txt','w');
$ekle=fwrite($dosyatwo,$urltwo);
fclose($dosyatwo);
putenv('LANG=tr_TR.UTF-8');
$command = escapeshellcmd('python3 odev4_b.py');
$output = shell_exec($command);
    }
}
?>
<body>
  <header>
    <h1 class="title">WEB İNDEXLEME UYGULAMASI</h1>
  </header>

  <section class="box">
    <div class="listGroup w-50">
      <ul class="list">
        <li class="list-item" data-filter="first">Frakans Hesaplama</li>
        <li class="list-item" data-filter="second">Anahtar Kelime Çkarma</li>
        <li class="list-item" data-filter="third">Benzerlik Skorlaması</li>
        <li class="list-item" data-filter="fourth">Site İndexleme ve Sıralama</li>
        <li class="list-item" data-filter="fifth">Semantik Analiz</li>
      </ul>
    </div>
    <div class="formBox w-50">
      <form class="active" action="" method="POST" data-filter="first">
        <input type="text" required name="hesapla">
        <button class="btn">Hesapla</button>
      </form>
      <form action="" method="POST" data-filter="second">
        <input type="text" required name="kelime">
        <button class="btn">Kelime Çıkar</button>
      </form>
      <form action="" method="POST" data-filter="third">
        <input type="text" required name="skora">
        <input type="text" required name="skorb">
        <button class="btn">Skorla</button>
      </form>
      <form action="" method="POST" data-filter="fourth">
        <input type="text" required name="indexle">
        <input type="text" required name="sirala">
        <button class="btn">İndexle ve Sırala</button>
      </form>
      <form action="" method="POST" data-filter="fifth">
        <input type="text" required name="analiz">
        <button class="btn">Analiz Et</button>
      </form>
    </div>
  </section>
<div id='container'> </div><?php echo $output; ?> </div>
  <script src="content/js/script.js"></script>
<script>var contain=document.querySelector('.btn');
contain.addEventListener('click',()=>{
    var x=document.querySelector('#container');
    x.innerHTML=' ';
})
</script>
</body>

</html>