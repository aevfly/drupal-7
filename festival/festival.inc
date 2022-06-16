<?php 

function festival_sendemailfilmmakers() {
  
  $cur_pass_fuid = '';
  $devnode = node_load(4156);
  $passed_fuid = $devnode->body['und']['0']['value'];
  $arr_passed_fuid = explode(',',$passed_fuid); 
    
  $query = 'SELECT ur.uid
    FROM {users_roles} AS ur
    WHERE ur.rid = :rid';
  $result = db_query($query, array(':rid' => '5'));
  $uids = $result->fetchCol();
  //dsm($uids);

  $i = 0;
    foreach ($uids as $uid) {
     if($i < 250)
        if(!in_array($uid, $arr_passed_fuid)){
           
          $fuser = user_load($uid); 
          dsm($fuser);  
          if(!empty($fuser->field_unsubscribe)){
            $unsubscr = $fuser->field_unsubscribe['und']['0']['value'];
          }
          if($unsubscr != 1){
            $femail = $fuser->mail;
            dsm($femail);
            // send email
            $subjemail  = _get_email5($fuser, $femail);
            $mail = array(
              'subject' => 'Introducing the WFP Black Friday Sale',
              'message' => $subjemail,
            );
            drupal_mail('system', 'Robert Miller', $femail, language_default(), array('context' => $mail), 'support@worldfilmpresentation.com');
            $cur_pass_fuid .=  ',' . $uid;
            
            $i++;
          }   
        }
    }  
      

  if(empty($passed_fuid)){
    $devnode->body['und']['0']['value'] = $cur_pass_fuid;  
    node_save($devnode);
  }else{
    $devnode->body['und']['0']['value'] = $passed_fuid . $cur_pass_fuid;
    node_save($devnode);
  }
  
  
}

function _get_email_filmmakers($account, $email){
  $username = $account->name; 
  if(!empty($username->field_first_name)){
    $username = $account->field_first_name['und']['0']['value']; 
  }elseif (!empty($account->data['ulogin'])){
    $username = $account->data['ulogin']['first_name']; 
  }
  
  return '<p>Hi '.$username.'</p><p><p dir="ltr" id="docs-internal-guid-446446aa-79c7-1898-d571-f0c94b3d9c77" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Good afternoon!</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">You submitted your film through our partners aggregator</span><a href="http://worldfilmpresentation.com/" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> </span><span style="font-size:10pt;font-family:Arial;color:#1155cc;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">http://worldfilmpresentation.com</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> &nbsp;and it has been highly recommended to us. Thank you for creating such a great film. </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">As a result of our work, we have managed to establish your film with some festivals and get the status of &ldquo;Preselection&rdquo; for you in four (4) festivals, with the possibility of you using their Laurels:</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">&nbsp;</span><a href="https://docs.google.com/document/d/1B7tr9bMI0ksmk2yDi5M6Se7y5bJO-47tOztgtGt7t2I/edit?usp=sharing" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">https://docs.google.com/document/d/1B7tr9bMI0ksmk2yDi5M6Se7y5bJO-47tOztgtGt7t2I/edit?usp=sharin</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">g </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Your official status means that you are at the Preselected stage at these 4 festivals now.</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">More information about this status can be read here: </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">http://worldfilmpresentation.com/preselected</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">If you agree with this status, you need to contact us, within a week, confirming your agreement with two mandatory references:</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">#1. Install on your website, or Facebook a &ldquo;Click to Submit&rdquo; &nbsp;button with a link to the page of the festivals on our aggregator:</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">For Facebook you should use: </span><a href="http://worldfilmpresentation.com/festivals" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">http://worldfilmpresentation.com/festivals</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">For website html code: </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">&lt;a href=&quot;http://worldfilmpresentation.com/festivals&quot; target=&quot;_blank&quot; title=&quot;Click to submit with WorldFilmPresentation&quot;&gt;</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">&lt;img src=&quot;http://worldfilmpresentation.com/sites/default/files/assets/wfp.png&quot; title=&quot;Click to submit with WorldFilmPresentation&quot; width=&quot;333&quot; height=&quot;100&quot;&gt;</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">&lt;/a&gt;</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">#2. Establish a minimum of 2 links to the festival&rsquo;s website indicating that your film has received the Preselection status at this festival. Alternatively, post 2 short reviews about the upcoming event which your film has received Preselection at. Examples of some links can be found here:</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><a href="https://www.worldradio.ch/events/film/near-myth-the-oskar-knight-story-at-eurocinema-fil/" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">https://www.worldradio.ch/events/film/near-myth-the-oskar-knight-story-at-eurocinema-fil/</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><a href="https://www.google.ru/search?hl=en&amp;as_q=film+festival+reviews&amp;as_epq=&amp;as_oq=&amp;as_eq=&amp;as_nlo=&amp;as_nhi=&amp;lr=lang_en&amp;cr=countryUS&amp;as_qdr=all&amp;as_sitesearch=&amp;as_occt=any&amp;safe=images&amp;as_filetype=&amp;as_rights=" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">https://www.google.ru/search?hl=en&amp;as_q=film+festival+reviews&amp;as_epq=&amp;as_oq=&amp;as_eq=&amp;as_nlo=&amp;as_nhi=&amp;lr=lang_en&amp;cr=countryUS&amp;as_qdr=all&amp;as_sitesearch=&amp;as_occt=any&amp;safe=images&amp;as_filetype=&amp;as_rights=</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">https://oscarnegroni.wordpress.com/short-films/stolen/</span><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><a href="https://filmfreeway.com/festivals/curated/top-100-best-reviewed-festivals" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">https://filmfreeway.com/festivals/curated/top-100-best-reviewed-festivals</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> (The reviews are below at the bottom of the festival submission page).</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">To get the status: &quot;Semi-Finalist&quot; you need to take the following steps:</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Before the festivals deadline arrives, please confirm that you are ready to send us the DCP, if you haven&rsquo;t previously sent it to us. When choosing several festivals you only need to send us the DCP once. You do not need to send a DCP for each festival separately. Having received your DCP, our Production Center will make a copy for the festivals you have chosen and will send them the DCP copies by mail. In this case, you will need to just pay the postage fees (about 20$ for location). The cost of copying the chipboard, buying hard drives, packaging, checking, sending, receiving, monitoring the testing, will be covered by us.</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">After you get the status of &quot;Semi-finalist&quot; - you will receive confirmation of the festival with the laurel &quot;Semi-finalist&quot;. This will mean that your film received preliminary permission to be shown, and is scheduled at this Festival after the quality of the DCP is checked (or at some festivals MP4, DVD, Blu-Ray formats) and after receiving the final decision of the Judicial Assembly for &quot;Finalist&quot; status. </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">We&rsquo;d like to inform you that at the festivals, only films with the status of &quot;Finalist&quot; are screened.</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Thank you once again for submitting your film.</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Hopefully your film will receive Finalist status soon..</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;">&nbsp;</p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Alexander Armstrong</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:#ffffff;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Film Festival Support Team</span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:#ffffff;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Submission: </span><a href="http://worldfilmpresentation.com" style="text-decoration:none;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:#ffffff;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">http://worldfilmpresentation.com</span></a><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:#ffffff;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"> </span></p><p dir="ltr" style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:10pt;font-family:Arial;color:#434343;background-color:#ffffff;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Email: filmfestivalhelp2016@gmail.com</span></p></p>.';
}

function _get_name_filmmakers($account, $email){
  $username = $account->name; 
  if(!empty($username->field_first_name)){
    $username = $account->field_first_name['und']['0']['value']; 
  }elseif (!empty($account->data['ulogin'])){
    $username = $account->data['ulogin']['first_name']; 
  }
  
  return $username;
}

function festival_sendemail() {

  $item = 0;
  $cur_pass_nodes = '';  
  $passed_nodes = variable_get('fest_node_uid'); //12,16,18 
  $arr_pass_nodes = explode(',',$passed_nodes);  

/**send to all registered festival
 *
 */
  $cur_pass_users = '';
  $fuser;
  $femail;
  $time_now = new DateTime(date("Y-m-d H:i:s")); // string date
  $time_user = new DateTime();  
  $pass_users = variable_get('pass_users');
  $arr_pass_users = explode(',',$pass_users);
  dsm(count($arr_pass_users));
  $query = 'SELECT ur.uid
    FROM {users_roles} AS ur
    WHERE ur.rid = :rid';
  $result = db_query($query, array(':rid' => '7'));
  $uids = $result->fetchCol();
  
  $i = 0;
    foreach ($uids as $uid) {
    if($i < 25)
        if(!in_array($uid, $arr_pass_users)){
          $fuser = user_load($uid);
          $time_user->setTimestamp($fuser->access);
          $interval =  $time_now->diff($time_user);   
          if($interval->d>3){
            $femail = $fuser->mail;
            dsm($femail);
            // send email
            $subjemail  = _get_email2($fuser, $femail);
            $mail = array(
              'subject' => 'Worldfilmpresentation film festival aggrigator platform',
              'message' => $subjemail,
            );
            drupal_mail('system', 'David Harris', $femail, language_default(), array('context' => $mail), 'support@worldfilmpresentation.com');
            $cur_pass_users .=  ',' . $uid;
            $i++;
          }
        }
    }  
  
    foreach($arr_pass_users as $uid){
      $luser = user_load($uid);
      
      $time2 = new DateTime();
      $time2->setTimestamp($luser->access);
      $interval =  $time_now->diff($time2);
      dsm($interval->format("%M month %H hours %i minutes %s seconds"));

    }

// end send to all registered festival
  
  if(empty($passed_nodes)){
    variable_set('pass_users' , $cur_pass_users);  
  }else{
    variable_set('pass_users' , $pass_users . $cur_pass_users);
  }
  
}


function _get_email($account, $email){
$link_site = '<a href="https://worldfilmpresentation.com/user">Worldfilmpresentation</a>';
  return '<p>
Hi ,

Thank you for joining our professional World Films aggrigator platform. 
Your registration is complete and you now have access to the essential resource for the entertainment industry, including contact and representation details, comprehensive title data, profile management tools, and more!

Your Account Information:
A site administrator has created an account for you. You may now log in by clicking this link or copying and pasting it to your browser:

'.user_pass_reset_url($account).'

This link can only be used once to log in and will lead you to a page where you can set your password.
After setting your password, you will be able to log in at https://worldfilmpresentation.com/user '.$link_site.' in the future using:

login: '.$email.'
password: Your password
 

Your festival submission is free. 
You can enter your account and make any correction or adjustments of your page.
Payouts for each montha??s entries are sent on the 10th day the following month.

Now you will start to get more film submissions to your festival. 
Our base has about 5000 films produced in 2015-2016 and we get about 150 new submissions every day.

New option! Free. If you like any film - you can select it and it would be on your festival.
New option! Free. The audience which like to watch film at his location and the location of your festival - can select the film which they like and recomend it to the filmmaker and to your festival to be screened.                                  
Enjoy your membership!  
  </p>';
}

function _get_email2($account, $email){

  return '<p>
  
Dear director

Did you have the time to add your festival ?

Any questions or comments?

log in at https://worldfilmpresentation.com/user?utm_source=welcome_email&utm_medium=email&utm_campaign=welcome_festival

Warm regards

David Harris

  </p>';
}


function _create_new_user($email){
  $new_user = array(
    'name' => $email,
    'pass' => user_password(), // note: do not md5 the password
    'mail' => $email,
    'status' => 1,
    'init' => $email,
    'roles' => array(
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
      7 => 'Film Festival',
    ),
  );
  
  // The first parameter is sent blank so a new user is created.
  user_save('', $new_user);
}

// send email to new festival
function festival_sendemailnfest() {
dsm('sendfest');
  // read write csv
  $row = 1;
  if (($handle = fopen("sites/all/modules/festival/listemails.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          $num = count($data);
          $row++;
          for ($c=0; $c < $num; $c++) {
              $line_data = explode(',',$data[$c]);
              
              //send email
            $subjemail  = _get_email3();
            $mail = array(
              'subject' => 'Worldfilmpresentation film festival aggrigator platform',
              'message' => $subjemail,
            );
              drupal_mail('system', 'David Harris', $line_data[0], language_default(), array('context' => $mail), 'invitation@worldfilmpresentation.com');
            $arr[] = $line_data;
          }
      }
      fclose($handle);
  }
  dsm($arr);
  //end read csv 
}

function _get_email3(){

  return '<p>
  
Dear director this is invitation to join Worldfilmpresentation, the platform for online submission to film festivals. This is our website: http://worldfilmpresentation.com
Joining Worldfilmpresentation is entirely free for festivals.

Any questions or comments?

Warm regards
David Harris

  </p>';
}

// send email to new festival
function festival_sendemailnfestexist() {
  
  $item = 0;
  $cur_pass_nodes = '';
  $nodes = node_load_multiple(NULL, array('type' => "list_your_festival", 'uid' => "118"));
  
  $passed_nodes = variable_get('fest_node_uid'); //12,16,18 
  $arr_pass_nodes = explode(',',$passed_nodes);  

  foreach ($nodes as $nid => $node) {
      if(!in_array($node->nid, $arr_pass_nodes)){
        if($item < 2){
        $fnode = $node;
         if(!empty($node->field_email)){
          $femail = $node->field_email['und'][0]['value'];
          $fuser = user_load_multiple(array(), array('mail' => $femail)); 
          if(empty($fuser)){
            _create_new_user($femail);
            $fuser = user_load_multiple(array(), array('mail' => $femail)); 
          }         
          
          $some_data[] = array($node->nid,$femail);
          
          // send email
          $subjemail  = _get_email4($fuser, $node);
          $mail = array(
            'subject' => 'Welcome to World Films Presentation platform',
            'message' => $subjemail,
          );
          drupal_mail('system', 'WorldFilmPresentation', $femail, language_default(), array('context' => $mail));
    
  
          $cur_pass_nodes .= $node->nid . ',';
          $item++;
        }
      }
    }    
  }
  
  variable_set('node_upd_uid' , serialize($some_data));
    

}


function _get_email4($account, $node){
  //dsm($account->uid);
  return '<p>
  
Thank you for your interest in Worldfilmpresentation!
Your listing looks great and The Worldfilmpresentation account for '.$node->title.' is now fully active for this seasona?™s call for entries: http://worldfilmpresentation.com/node/'.$node->nid.'

Thank you for being a part of our community. From the entire Worldfilmpresentation team, we wish you a successful event!

You login: '.$account->mail.'
You may now log in by clicking this link or copying and pasting it to your browser:

'.user_pass_reset_url($account).'

To build a positive reputation with the Worldfilmpresentation filmmaker community, respond to filmmaker inquiries promptly. 
Keep this email handy throughout your season as it contains useful links and information. 
Best Practices for a Successful Call for Entries.

Thank you! 

Sincerely, 
ROBERT MILLER  
Worldfilmpresentation Festivals Team

  </p>';
}


function _get_email5($account, $email){

$name = _get_name_filmmakers($account, $email);
  return '<div style="width:800"><p style="text-align:center"><img src="https://worldfilmpresentation.com/sites/default/files/pictures/bF.jpg" width="480"></p><p><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Hi '.$name.'</span></p><p><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Your favourite stores do it and now World Film Presentation are doing it. </span></p><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">We have a great deal for you. We are allowing you to submit to two festivals at a reduced rate. If you pay a $30 submission fee, we will grant you two tokens to use to submit to any two festivals* of your choice on the World Film Presentation website. That&rsquo;s two festival submissions for $30! See a full list of festivals on the website: </span><a href="https://worldfilmpresentation.com/festivals" style="text-decoration:none;"><span style="font-size:11pt;font-family:Arial;color:#1155cc;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:underline;vertical-align:baseline;">https://worldfilmpresentation.com/festivals</span></a></p><br /><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">*The following festivals are excluded from the offer, but that still leaves over 50 festivals to choose from!:</span></p><ul style="margin-top:0pt;margin-bottom:0pt;"><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Madrid International Film Festival</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Madrid Asia International Film Festival</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">London International Film Festival of World Cinema</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Nice International Film Festival South of France, Held just before the Cannes Film Festival</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Amsterdam International Filmmaker Festival of World Cinema</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Milan International Filmmaker Festival</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Bolton International Film Festival</span></p></li><li style="list-style-type:disc;font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;"><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;text-align: justify;"><span style="font-size:9pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">ECaff</span></p></li></ul><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Contact us before December 1st, 2017, if you are interested in the offer so we can arrange it for you. This is a limited time offer that you will not receive from any other festival submission platform.</span></p><br /><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Best Wishes,</span></p><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">Robert Miller</span></p><p style="line-height:1.38;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:11pt;font-family:Arial;color:#000000;background-color:transparent;font-weight:400;font-style:normal;font-variant:normal;text-decoration:none;vertical-align:baseline;">World Film Presentation Director</span></p></div>';
}


function _node_update_uid($fnode, $fuser){

          $fnode->uid = $fuser->uid;
          $fnode->name = $fuser->mail;
          node_save($fnode); 
}


// not finished
function filmmaker_sendemail(){

  $item = 0;
  $cur_pass_nodes = '';
  
  $passed_nodes = variable_get('fest_node_uid'); //12,16,18 
  $arr_pass_nodes = explode(',',$passed_nodes);  
  dsm($arr_pass_nodes);
  //dsm($nodes);


/**send to all registered filmmaker
 *
 */

  $cur_pass_users = '';
  $fuser;
  $femail;
  $time_now = new DateTime(date("Y-m-d H:i:s")); // string date
  $time_user = new DateTime();  
  $pass_users = variable_get('pass_users');
  $arr_pass_users = explode(',',$pass_users);
  dsm(count($arr_pass_users));
  $query = 'SELECT ur.uid
    FROM {users_roles} AS ur
    WHERE ur.rid = :rid';
  $result = db_query($query, array(':rid' => '7'));
  $uids = $result->fetchCol();
  
  $i = 0;
    foreach ($uids as $uid) {
    if($i < 25)
        if(!in_array($uid, $arr_pass_users)){
          $fuser = user_load($uid);
          $time_user->setTimestamp($fuser->access);
          $interval =  $time_now->diff($time_user);   
          if($interval->d>3){
            $femail = $fuser->mail;
            dsm($femail);
            // send email
            $subjemail  = _get_email2($fuser, $femail);
            $mail = array(
              'subject' => 'Worldfilmpresentation film festival aggrigator platform',
              'message' => $subjemail,
            );
            $cur_pass_users .=  ',' . $uid;
            $i++;
          }
        }
    }  
  
    foreach($arr_pass_users as $uid){
      $luser = user_load($uid);
      
      $time2 = new DateTime();
      $time2->setTimestamp($luser->access);
      $interval =  $time_now->diff($time2);
      dsm($interval->format("%M month %H hours %i minutes %s seconds"));

    }

// end send to all registered festival
  
  if(empty($passed_nodes)){
    variable_set('pass_users' , $cur_pass_users);  
   }else{
    variable_set('pass_users' , $pass_users . $cur_pass_users);
  }
  
}
