recalculateServiceTime();
$('.priority-only').hide();

$(document).ready(function () {
  $('input[type=radio][name=algorithm]').change(function () {
    if (this.value == 'priority') {
      $('.priority-only').show();
      $('.servtime').show();
      $('#minus').css('left', '604px');
    }
    else {
      $('.priority-only').hide();
      $('.servtime').show();
      $('#minus').css('left', '428px');
    }

    if (this.value == 'robin') {
      $('.servtime').hide();
      $('#quantumParagraph').show();
    }
    else {
      $('#quantumParagraph').hide();
      $('.servtime').show();
    }

    recalculateServiceTime();

    console.log(recalculateServiceTime);
  });
});

function addRow() {
  var lastRow = $('#inputTable tr:last');
  var lastRowNumebr = parseInt(lastRow.children()[1].innerText);

  var newRow = '<tr><td>P'
  + (lastRowNumebr + 1)
  + '</td><td>'
  + (lastRowNumebr + 1)
  + '</td><td><input class="exectime" type="text"/></td><td class="servtime"></td>'
  +'<td class="priority-only"><input type="text" /></td>'
  +`<td><form id="algorithm"><input type="algorithm" value=${lastRowNumebr + 2}></form></td></tr>`;

  lastRow.after(newRow);

  var minus = $('#minus');
  minus.show();
  minus.css('top', (parseFloat(minus.css('top')) + 24) + 'px');

  if ($('input[name=algorithm]:checked', '#algorithm').val() != "priority")
    $('.priority-only').hide();


  $('#inputTable tr:last input').change(function () {
    recalculateServiceTime();
  });
}

function deleteRow() {
  var lastRow = $('#inputTable tr:last');
  lastRow.remove();

  var minus = $('#minus');
  minus.css('top', (parseFloat(minus.css('top')) - 24) + 'px');

  if (parseFloat(minus.css('top')) < 150)
    minus.hide();
}

$(".initial").change(function () {
  recalculateServiceTime();
});

function recalculateServiceTime() {
  var inputTable = $('#inputTable tr');
  var totalExectuteTime = 0;

  var algorithm = $('input[name=algorithm]:checked', '#algorithm').val();
  if (algorithm == "fcfs") {
    $.each(inputTable, function (key, value) {
      if (key == 0) return true;
      $(value.children[3]).text(totalExectuteTime);

      var executeTime = parseInt($(value.children[2]).children().first().val());
      totalExectuteTime += executeTime;
    });
    
  }


  else if (algorithm == "robin") {
    $('#minus').css('left', '335px');
    $.each(inputTable, function (key, value) {
      if (key == 0) return true;
      $(value.children[3]).text("");
    });
  }
}



function animate() {
  var sum = 0;
  $('.exectime').each(function() {
    var mayor = Number($(this).val())
    if(sum < mayor) {
      sum = mayor;
    }
  });
  
  var distance = $(".bar").css("width");
  console.log(sum, distance);
  
  animationStep(sum, 0);

  jQuery('#resultTable').animate({ width: '100%'}, sum*1000, 'linear');
}

function animationStep(steps, cur) {
	$('#timer').html(cur);
	if(cur < steps) {
		setTimeout(function(){ 
   	     animationStep(steps, cur + 1);
          console.log(cur, steps)
  	}, 500);
  }
}

function draw() {
  $('fresh').html('');
  var inputTable = $('#inputTable tr');
  var div1 = '';
  var div2 = '';
  var div3 = '';

  $.each(inputTable, function (key, value) {
    if (key == 0) return true;
    var executeTime = parseInt($(value.children[2]).children().first().val());//burst time
    var width = 'style="width: ' + executeTime * 20 + 'px;"';
    div1 += '<div style="width: 20px">P' + (key - 1) + '</div>';
    div2 += `<div class="bar" ${width}>` + executeTime + '</div>';
    div3 += '<div class="block">' + div1 + div2 + '</div>'
    div1 = div2 = '';
  });


  $('fresh')
    .html('<div id="resultTable" style="width: 20px"><tr>'
          + div3
          + '</tr></div>'
        );

  animate();
}