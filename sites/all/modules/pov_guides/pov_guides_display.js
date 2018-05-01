// JavaScript Document
var xmlHttp;
var lsub
var numMenus = 4
var headnum = 0
var aguide = cguide.split("-")
var omydoc = null
function getguidelines(jpercent,jperiod,lnoheader){
    //alert('1')
    ctext = ""
    period = jperiod
    period = String(period)
    if (period.toLowerCase() in oc(["annual","monthly","weekly"]) ){
        if (period == "annual" ){
            var cperiod = "Annual Income"
            period = 1
        }
        if (period == "monthly" ){
            var cperiod = "Monthly Income"
            period = 12
        }
        if (period == "weekly" ){
            var cperiod = "Weekly Income"
            period = 52
        }		
    }
    else{
        var cperiod = "Annual Income"
        period = 1
    }
    //alert(jpercent.length);
    //alert('2')
    if (jpercent.length == 1){
            percent = jpercent[0]
            cpercent = String(percent) + "% of the Federal Poverty Guidelines";
            percent = percent/100
            var ctext = ctext + "<table class='pov_guide' cellspacing='0' cellpadding='5' border='1' align='center'>"
            if (lnoheader == true) {}
            else{
                ctext = ctext + "<caption><b>The " + cyear + " Poverty Guidelines for the<br/>"
                ctext = ctext + "48 Contiguous States and the District of Columbia<br />"
                ctext = ctext + cpercent + "</b></caption>"
            }
            ctext = ctext + "<tbody><tr valign='bottom'>"
            ctext = ctext + "<th scope='col' align='center'>Persons in family</th>"
            ctext = ctext + "<th scope='col' align='center'>" + cperiod + "</th></tr>"
            for (var k=1;k<aguide.length-1;k++){
                //alert('3:' + String(k) )
                ctext = ctext + "<tr align='center'><td>" + String(k) + "</td><td>" + formatCurrency(Math.ceil(aguide[k]*percent/period)) + "</td></tr>"
            }
            ctext = ctext + "<tr align='center'><td colspan='2'><small>For families with more than 8 persons, add " 
            ctext = ctext + formatCurrency(Math.ceil(aguide[0]*percent/period))
            ctext = ctext + " for each additional person.</small></td></tr>" 
            ctext = ctext + "</tbody></table>"
    }
    else{
        var ctext = ctext + "<table class='pov_guide' cellspacing='0' cellpadding='5' border='1' align='center'>"
        if (lnoheader == true) {}
        else{
            ctext = ctext + "<caption><b>The " + cyear + " Poverty Guidelines for the<br/>"
            ctext = ctext + "48 Contiguous States and the District of Columbia<br />"
        }
        ctext = ctext + cperiod + "<br>"
        ctext = ctext + "<tbody><tr align='center'>"
        ctext = ctext + "<th scope='col' valign='middle'><center>Persons in family</center></th>"
        for ( t=0;t<jpercent.length;t++){
            percent = jpercent[t]
            ctext = ctext + "<th align='center'><center>" + String(percent) + "%</center></th>"
        }
        ctext = ctext + "</tr>"
        for (var k=1;k<aguide.length-1;k++){
            //alert('4:' + String(k) )
            ctext = ctext + "<tr align='center'><td>" + String(k) + "</td>"
            for ( t=0;t<jpercent.length;t++){
                percent = jpercent[t]
                cpercent = String(percent) + "% of the Federal Poverty Guidelines"
                percent = percent/100
                ctext = ctext + "<td>" + formatCurrency(Math.ceil(aguide[k]*percent/period)) + "</td>"
            }
            ctext = ctext + "</tr>"
        }
        ctext = ctext + "<tr align='center'><td>Each Additional Person</td>"
        for ( t=0;t<jpercent.length;t++){
            percent = jpercent[t]
            cpercent = String(percent) + "% of the Federal Poverty Guidelines"
            percent = percent/100
            ctext = ctext + "<td>" + formatCurrency(Math.ceil(aguide[0]*percent/period)) + "</td>"
        }
        ctext = ctext + "</tr>"
        ctext = ctext + "</tbody></table>"
    }
    //alert('5');
    jQuery('.guidediv a').hide();
    //alert('6');
    return ctext;
}
function formatCurrency(Num){
    Num = '' + parseInt(Num);
    var temp1 = '';
    var temp2 = '';
    var count = 0;
    for (var k = Num.length-1; k >= 0; k--) {
        var oneChar = Num.charAt(k);
	if (count == 3) {
            temp1 += ',';
            temp1 += oneChar;
            count = 1;
            continue;
        }
	else {
            temp1 += oneChar;
            count ++;
	}
    }
    for (var k = temp1.length-1; k >= 0; k--) {
        var oneChar = temp1.charAt(k);
	temp2 += oneChar;
    }
    temp2 = '$' + temp2;
    return temp2
}
function showguides(odoc){ 
	var mypercent = odoc.myform.percent.value
	var myperiod = odoc.myform.value
	odoc.getElementById("guidediv").innerHTML = getguidelines(mypercent,myperiod)
}
function oc(a){
  var o = {};
  for(var i=0;i<a.length;i++)
  {
	o[a[i]]='';
  }
  return o;
}