// JavaScript Document

function oc(a)
{
  var o = {};
  for(var i=0;i<a.length;i++)
  {
	o[a[i]]='';
  }
  return o;
}

function getguidelines(jpercent,jperiod,lnoheader)
{
ctext = ""
if (! document.getElementById("getpref") == null)
	{document.getElementById("getpref").style.visibility = "hidden"}

if (jpercent.length == 1)
	{
	percent = jpercent[0]
	period = jperiod
	//document.getElementById("getpref").style.visibility = "hidden"
	if (percent in oc(["100","125","130","133","150","165","170","185","200","250","300","350"]) )
		{
			cpercent = String(percent) + "% of the Federal Poverty Guidelines"
			percent = percent/100
		}
	else
		{
			cpercent = "100% of the Federal Poverty Guidelines"
			percent = 1
		}
	
	period = String(period)
	
	if (period.toLowerCase() in oc(["annual","monthly","weekly"]) )
		{
		 if (period == "annual" )
			{
				var cperiod = "Annual Income"
				period = 1
			}
		 if (period == "monthly" )
			{
				var cperiod = "Monthly Income"
				period = 12
			}
		 if (period == "weekly" )
			{
				var cperiod = "Weekly Income"
				period = 52
			}		
		}
	else
		{
			var cperiod = "Annual Income"
			period = 1
		}
		
	var ctext = ctext + "<table cellspacing='0' cellpadding='5' border='1' align='center'>"
	if (lnoheader == true) {}
	else
		{
			ctext = ctext + "<caption><b>The " + cyear + " Poverty Guidelines for the<br/>"
			ctext = ctext + "48 Contiguous States and the District of Columbia<br />"
			ctext = ctext + cpercent + "</b></caption>"
		}
	ctext = ctext + "<tbody><tr valign='bottom'>"
	ctext = ctext + "<th scope='col' align='center'>Persons in family</th>"
	ctext = ctext + "<th scope='col' align='center'>" + cperiod + "</th></tr>"
	for (var k=1;k<aguide.length-1;k++)
		{ctext = ctext + "<tr align='center'><td>" + String(k) + "</td><td>" + formatCurrency(Math.ceil(aguide[k]*percent/period)) + "</td></tr>"}
	ctext = ctext + "<tr align='center'><td colspan='2'><small>For families with more than 8 persons, add " 
	ctext = ctext + formatCurrency(Math.ceil(aguide[0]*percent/period))
	ctext = ctext + " for each additional person.</small></td></tr>" 
	ctext = ctext + "</tbody></table>"
	}
else
	{
	var ctext = ctext + "<table cellspacing='0' cellpadding='5' border='1' align='center'>"
	if (lnoheader == true) {}
	else
		{
			ctext = ctext + "<caption><b>The " + cyear + " Poverty Guidelines for the<br/>"
			ctext = ctext + "48 Contiguous States and the District of Columbia<br />"
		}

	period = jperiod
	period = String(period)
	
	if (period.toLowerCase() in oc(["annual","monthly","weekly"]) )
		{
		 if (period == "annual" )
			{
				var cperiod = "Annual Income"
				period = 1
			}
		 if (period == "monthly" )
			{
				var cperiod = "Monthly Income"
				period = 12
			}
		 if (period == "weekly" )
			{
				var cperiod = "Weekly Income"
				period = 52
			}		
		}
	else
		{
			var cperiod = "Annual Income"
			period = 1
		}
	ctext = ctext + cperiod + "<br>"
	ctext = ctext + "<tbody><tr align='center'>"
	ctext = ctext + "<th scope='col' valign='middle'><center>Persons in family</center></th>"
	for ( t=0;t<jpercent.length;t++)
		{
			percent = jpercent[t]
			ctext = ctext + "<th align='center'><center>" + String(percent) + "%</center></th>"
		}
	ctext = ctext + "</tr>"
	for (var k=1;k<aguide.length-1;k++)
		{
			ctext = ctext + "<tr align='center'><td>" + String(k) + "</td>"
			for ( t=0;t<jpercent.length;t++)
				{
					percent = jpercent[t]
					if (percent in oc(["100","125","130","133","150","165","170","185","200","250","300","350"]) )
						{
							cpercent = String(percent) + "% of the Federal Poverty Guidelines"
							percent = percent/100
						}
					else
						{
							cpercent = "100% of the Federal Poverty Guidelines"
							percent = 1
						}
					ctext = ctext + "<td>" + formatCurrency(Math.ceil(aguide[k]*percent/period)) + "</td>"
				}
			ctext = ctext + "</tr>"
		}
	ctext = ctext + "<tr align='center'><td>Each<br>Additional<br>Person</td>"
	for ( t=0;t<jpercent.length;t++)
		{
			percent = jpercent[t]
			if (percent in oc(["100","125","130","133","150","165","170","185","200","250","300","350"]) )
				{
					cpercent = String(percent) + "% of the Federal Poverty Guidelines"
					percent = percent/100
				}
			else
				{
					cpercent = "100% of the Federal Poverty Guidelines"
					percent = 1
				}
			ctext = ctext + "<td>" + formatCurrency(Math.ceil(aguide[0]*percent/period)) + "</td>"
		}
	ctext = ctext + "</tr>"
	ctext = ctext + "</tbody></table>"
	}
document.getElementById("guidediv").innerHTML = ctext
//return ctext
}

function formatCurrency(Num) 
{
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

function showcontent(cfile, cElement)
{
xmlHttp=GetXmlHttpObject();
if (xmlHttp==null)
 {
 alert ("Browser does not support HTTP Request");
 return;
 }

document.getElementById(cElement).innerHTML = cfile
var url=cfile;
xmlHttp.onreadystatechange= function() {stateChanged(cElement);};
xmlHttp.open("GET",url,true);
xmlHttp.send(null);
}

function stateChanged(cElementID) 
{ 
if (xmlHttp.readyState==4 || xmlHttp.readyState=="complete")
 {document.getElementById(cElementID).innerHTML=xmlHttp.responseText}
}

function GetXmlHttpObject()
{
var xmlHttp=null;
try
 {
 // Firefox, Opera 8.0+, Safari
 xmlHttp=new XMLHttpRequest();
 }
catch (e)
 {
 //Internet Explorer
 try
  {
  xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
  }
 catch (e)
  {
  xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
 }
return xmlHttp;
}