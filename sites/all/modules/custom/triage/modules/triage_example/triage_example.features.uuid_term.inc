<?php
/**
 * @file
 * triage_example.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function triage_example_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'I live in Canada and my case will be tried there.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '00147209-666a-45d8-9c59-7870fc6bdce2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b401fe9d-9865-48b2-8326-5962c259d514',
    ),
  );
  $terms[] = array(
    'name' => 'I own my own home or am buying a home.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '00b8afef-bf42-4520-a1a7-e28f384bfa8c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7501a644-65bd-4e23-82af-86857bba181c',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord has locked me out.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => '00c7aa59-a0d7-4885-a1a7-48de8d284188',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '631 - PRIV Eviction',
          'format' => NULL,
          'safe_value' => '631 - PRIV Eviction',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with my finances or planning for the future when I can\'t take care of my own finances.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '011e040a-1234-4626-b884-aa4104581292',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'None of these statements fits my situation.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '01817fdc-a5ad-40be-ad50-b7b9fe381b4d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad7cb45a-033e-467c-936a-09bcfad3e732',
    ),
  );
  $terms[] = array(
    'name' => 'I want to change my name or the name of my minor child.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '01b2380d-d35b-496c-b34c-b1aa06ccd3fd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'fd55042b-8fa2-49e9-b73f-d747e8771702',
    ),
  );
  $terms[] = array(
    'name' => 'My issue is not related to my age; it is one that affects people of all ages (such as eviction, health care, or consumer fraud).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '020e4bf6-fedd-4baf-bf67-b7ecb904c921',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '593149a7-b796-4947-a9ab-7e8ae6d2c237',
    ),
  );
  $terms[] = array(
    'name' => 'I need money for a new heating system.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '0218a24d-f5ab-4ccc-b73e-11a7569cb7b0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '31a6da4f-a038-412b-af35-a6c39f4e908e',
    ),
  );
  $terms[] = array(
    'name' => 'I am in jail or prison and need legal help with a divorce or some other issue not related to my criminal offense.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '0227beb0-ecbb-41df-83d4-2958e741ef31',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f0020f81-3f84-42d3-9928-d3def15acac2',
    ),
  );
  $terms[] = array(
    'name' => 'My child refuses to attend school.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '027e5908-eaed-4cfb-837b-e73072bdb70f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '143 - EDU Truancy',
          'format' => NULL,
          'safe_value' => '143 - EDU Truancy',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'My problem is with my propane or firewood supplier.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '0283a18a-eccc-4fdf-9c31-f1931139450d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'I am not getting time and a half for hours over 40.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '037a2850-fbb0-418a-97f9-3dbab0ed012d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for TANF but don\'t think DHHS is giving me as much as I should get.',
    'description' => '
',
    'format' => '2',
    'weight' => '1',
    'uuid' => '0480d128-c028-419e-8ad6-13c0d5fcf574',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '712 - TANF Eligibility',
          'format' => NULL,
          'safe_value' => '712 - TANF Eligibility',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9d2eba9c-cc98-4569-b093-f8a1172e9ba4',
    ),
  );
  $terms[] = array(
    'name' => 'My child is struggling in school and needs help and more services.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => '04882722-da8d-4136-9ece-55120acf9467',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with ASPIRE (TANF-related work/training program) or PaS (TANF-related education program).',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '05e8665f-5e85-4773-944b-625b548ae26a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with consumer debt (credit cards, small claims court judgments, etc.).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with Maine Revenue Services (state income taxes).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '06f4a7d3-c02e-43bb-b9ed-89c9c1442c2a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'bad14cf3-9a7e-4e33-a94c-7685c0079e59',
    ),
  );
  $terms[] = array(
    'name' => 'I have a complaint about a hospital, doctor, or other medical provider.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '07c63bd5-2464-4430-a3a9-8a49c64e5765',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'I am facing criminal charges/traffic violation issues.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '087afcd8-b2ab-4ca3-b646-a6fbdef5dfcb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    ),
  );
  $terms[] = array(
    'name' => 'The problem is with my land line phone bill.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '08b9c7b7-d744-42b1-8902-6659cfe7e288',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'The reason for my being fired relates to my sex, pregnancy, sexual orientation, race, color, disability, religion, age, ancestry, national origin, or reporting unsafe or illegal behavior.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '09b29650-81ca-410f-9244-00973629b092',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '13e5ef58-03e7-4903-8ac2-5ed8d01d76f8',
    ),
  );
  $terms[] = array(
    'name' => 'I am disabled and need a "reasonable accommodation" (such as a service animal, wheelchair access, or other changes to my rental).',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '0a13a22e-972e-44f6-a974-d041301c198b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '631RA - PRIV Reasonable Accommodation',
          'format' => NULL,
          'safe_value' => '631RA - PRIV Reasonable Accommodation',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I am being summonsed back to court to see what I can pay on a debt.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '0a4d522c-dcd0-45f6-a120-25c431d81c7e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord is harassing me or violating my rights in some other way.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '0c173c02-ffd8-432a-ba80-048417b93d1f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '639 - PRIV Other Private Landlord/Tenant',
          'format' => NULL,
          'safe_value' => '639 - PRIV Other Private Landlord/Tenant',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I have another type of legal issue that does not relate to my military veteran status (such as eviction or consumer debt).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => '0ca2bd52-48fa-480a-94c3-abc5b75ab88b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    ),
  );
  $terms[] = array(
    'name' => 'I need my personnel file to help me with my claim for unemployment, illegal discrimination, or other legal claim.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '0cb80a74-ab52-4489-85d1-b2b3a63ec978',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7d5d6682-9821-4d3a-a7af-6749f1ebaa88',
    ),
  );
  $terms[] = array(
    'name' => 'I have a child with a school-related issue. (NOTE: Although we are addressing parents, others can use this tool.)',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '45bbeff5-0de4-493d-bd09-8000b96af17a',
    ),
  );
  $terms[] = array(
    'name' => 'I am not planning to use the file to pursue a legal claim against my employer; I just want to see my file because I have the right to it or because I need my performance reviews to get a new job.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '0d76b53c-1be3-474c-9a5d-b338b16eab89',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7d5d6682-9821-4d3a-a7af-6749f1ebaa88',
    ),
  );
  $terms[] = array(
    'name' => 'There are bad park conditions.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '0e27dc8b-20e0-4700-b582-2a0542551202',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '654 - MOBILE Warranty Habit/Park Cond',
          'format' => NULL,
          'safe_value' => '654 - MOBILE Warranty Habit/Park Cond',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '78f5751f-e6ea-4460-984c-cb743da5c743',
    ),
  );
  $terms[] = array(
    'name' => 'The IRS is in the process of auditing me and I have questions.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '0ecd3e9a-c370-4ad1-a6e0-f7c3911690b1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '241 - TAX Federal/Federal & State Taxes',
          'format' => NULL,
          'safe_value' => '241 - TAX Federal/Federal &amp; State Taxes',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad7cb45a-033e-467c-936a-09bcfad3e732',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with my EBT card.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '0ef87682-c699-4909-bfce-4afdfbbd0b14',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '555ee673-8f46-4dc6-a40b-ac4365807b55',
    ),
  );
  $terms[] = array(
    'name' => 'My former employer won\'t give out any information.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '0fc3e315-6215-49e9-8871-0a43b98c6c9a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '80039820-9209-4d59-9d50-b30b516d8e35',
    ),
  );
  $terms[] = array(
    'name' => 'A family law case (such as divorce or child custody) has been started during my deployment.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '0ff657f1-069f-4525-9e20-9fc951c70c34',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5afb78bd-fc4d-4555-bd52-3dac7a9146a3',
    ),
  );
  $terms[] = array(
    'name' => 'I have a question or problem regarding identity theft',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => '10203af7-8605-4fb6-ba14-617fdae48265',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    ),
  );
  $terms[] = array(
    'name' => 'I want  to get unemployment insurance benefits.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '106a8769-7f4d-4d3a-a823-9a6010f5bb44',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'de934714-cdfb-4476-9a1e-5c3d1c3d6896',
    ),
  );
  $terms[] = array(
    'name' => 'I have been charged with an overpayment.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '10f22994-3c46-4b77-875d-81be2d194b4b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e64887db-bf03-4362-9ee9-0f5ff447d301',
    ),
  );
  $terms[] = array(
    'name' => 'I am being evicted.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '1101edf2-e6e0-4256-afa6-68d226c2f340',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '641 - PUBLIC Eviction',
          'format' => NULL,
          'safe_value' => '641 - PUBLIC Eviction',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f038138e-92ac-4103-a846-4a8dd46b6547',
    ),
  );
  $terms[] = array(
    'name' => 'I have an issue with getting help from my town.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6d39bcdb-2d69-4188-8cfc-11024794536a',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with TANF (Temporary Assistance to Needy Families).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-4',
    'uuid' => '119990b0-9a61-4daa-9465-86d3627e80ec',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'I need financial help.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '11cd8b3d-04eb-430c-8458-a2b6d875792a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ef6ffce8-ae1e-4df0-9e72-92c9ca1a34b7',
    ),
  );
  $terms[] = array(
    'name' => 'I have been served with court papers saying that the bank is foreclosing.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '13ccb7d2-ece5-4b19-a02a-129a9292dee6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '970d6f59-bbc4-4a96-966e-fa74c6d45ffd',
    ),
  );
  $terms[] = array(
    'name' => 'I do not have written copies of my former employer\'s work rules and records of the amounts owed to me.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '13dcbae8-db68-4a4f-9a2b-3ac4c455070a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b77a2787-42f9-41b0-b32e-b2915d4bbb8b',
    ),
  );
  $terms[] = array(
    'name' => 'I was fired for something that happened outside of work.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '13e5ef58-03e7-4903-8ac2-5ed8d01d76f8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '66b0e165-af42-404e-a74a-aea285e61456',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a similar problem with my federal taxes for the same tax year.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '14396e32-c2a2-4bee-ace3-f74a9b1e2e99',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '241 - TAX Federal/Federal & State Taxes',
          'format' => NULL,
          'safe_value' => '241 - TAX Federal/Federal &amp; State Taxes',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '06f4a7d3-c02e-43bb-b9ed-89c9c1442c2a',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem relating to the juvenile justice system.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '144cc61d-c199-4a43-a4cf-c626735624b2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f39a9ae3-9929-4362-95d8-3e770f66eecc',
    ),
  );
  $terms[] = array(
    'name' => 'I am being evicted.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-6',
    'uuid' => '14a537c1-8f1d-4631-81d2-9492cd2fc9a4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'The harassment relates to my sex, pregnancy, sexual orientation, race, color, disability, religion, age, ancestry, national origin, or reporting unsafe or illegal behavior.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '14b0afce-fcf1-4572-9cc0-732b7f9b912d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '58ac6fd2-954d-41c6-9706-81d95c49fdf6',
    ),
  );
  $terms[] = array(
    'name' => 'I am an immigrant to the U.S. and have a legal issue relating to my status as an immigrant.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '14b6d251-10e7-4177-8938-b04cc982baff',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8ec455e1-1737-4ed7-a97a-6896c8fe43e6',
    ),
  );
  $terms[] = array(
    'name' => 'I have other questions about my child\'s need for extra educational services.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '14ef9a39-cfd7-4950-ad2a-46a738c3cd69',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '132 - EDU Programming',
          'format' => NULL,
          'safe_value' => '132 - EDU Programming',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '04882722-da8d-4136-9ece-55120acf9467',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for Food Stamps but don\'t think DHHS is giving me as much as I should get.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '15230c11-81ca-43cf-bd1a-334b8b26dc02',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '731 - SNAP General',
          'format' => NULL,
          'safe_value' => '731 - SNAP General',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '558cd122-db93-4f43-adc9-be37f59ff004',
    ),
  );
  $terms[] = array(
    'name' => 'My family law issue is about something else.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'af936db2-1290-4648-97f9-5b53d0fc4f9a',
    ),
  );
  $terms[] = array(
    'name' => 'Where are low-cost and no-cost clinics in Maine?',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '15ba1dd9-6ec7-4add-9b23-7a308a734554',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4120096d-a572-4152-9528-32b2a6d0187c',
    ),
  );
  $terms[] = array(
    'name' => 'Other',
    'description' => 'accidents, being sued, harassment, Constitutional rights, losing your license, human trafficking and more',
    'format' => '2',
    'weight' => '4',
    'uuid' => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'world-icon.png',
          'uri' => 'public://world-icon.png',
          'filemime' => 'image/png',
          'filesize' => '2238',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '28ee447b-f2dd-401b-b5b2-5620e361ee4b',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6RkQzRDdGMkY0QzhBMTFFM0E2QzRGMUY2RjgzOEE1QjIiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6RkQzRDdGMzA0QzhBMTFFM0E2QzRGMUY2RjgzOEE1QjIiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpGRDNEN0YyRDRDOEExMUUzQTZDNEYxRjZGODM4QTVCMiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpGRDNEN0YyRTRDOEExMUUzQTZDNEYxRjZGODM4QTVCMiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Pjzzw6UAAAUySURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoqEMHF2ChlkHKMmImWvJK0qIiArzF/SvL4j1YmJkfPn977sbD6/efD7xDhfi5tRSlbj96uaojg4OdFSIIdKilnoqanDiQ/f///5ia2X/+/fv4+fvjl+8GIOp5ONnL4z13Ty3+z/A/OcAW7ko0wMjImBXq9Ortp/W92bWpvvw8nHR1qK6KzJrurDgfqyev3l+6/STQ0QiPYit9ZV5uzr2nrke4mW3syzXTUaSTQ4OdjJe0pMiKCwHZy3accDHT4uJgw6MeGKiBjoZr950FskUFeefUJOD3GHUcGuZq2pjhD8woQPa///+B4eRuqU1Ql7ulztlrD99//gZkMzMzNWcGhLiY0NChFrpKNSk+wBCCcK/cefrl208LXWWCGqVEBeQlhQ+fvwUP47pUX2NNeZo4FJgPOvNCmZkQWs5ef6CrKsPKwkyMdqCzzl5/COcCzenOD+Pl4qB+8QQMOaDLkEX2nr7Oz8O18/gVTMXHLt65//Q1muCJy3fRFAMzFjDxEGM7I5GdO052NmEBbjTBZ68+CAvwsLOh+/bJy/fiwnxoIf3377/nbz4C0wATEyOy+JsPX378/E21EM2LcAYWRsgiP3//MYluml4Zq6koiaZYO7R2RlUcpMCHA6BrTGKbZ1bHAWsvZPG5Gw73Ld1FnTTKxMjobauHJvj8zQdgrgeGEJFeBdYIIgI8T1+9RxP3tTeA505KHaqlLCXMz4Mm+OLNJ6DdJNU0YkJ8L99+QhcU5NVQkKCOQ/VUZDAFP339LsjLRVLpBvTVhy/fsJivKkMdh6KlKphDf3BxsJPmUG7Or99/YYqryIpTLTMBMzKayJv3n4F1DKY4BLx8+5GLHb1e/fHr96t3n3BpoU7xNDQazjUpvrYGqmiCWw5f3HH8ypSyaCw1e07fjKpYRSn0BNOxYJsgH1d6kAOa+P6zNzrmb6NO1MuIC6KJAIv0P3//YYrDZPkxpTjYWIEZH1P8/7//1MlMdx69xBQEVtPfvv8kKfo+fvmGtUF498kr6jj04u3HWLIwL9fHL99JdOh3AWwl2sXbT6jj0BsPXrx4+xFNUEKYD5iL3336SrxDX7z9JCmCXpM9ff3hNrYYI8ehwA7ahgPn0QQlRfiBxdPz1x+IdOW3H7/efvwijVHlbth/jprFE6Smxmw9AXuhmN06PK0noEMZ0VpP778AY4ZqBT6w7aOhIOllrYssuGTbCWDmCHJC7wAV9a2M87YCBjmy4JELt09duV8U44YsuPXIpScvr1OtHIWAk1fuVSf7ANsQSNXPJ2BDGNgfwlC70kpfBa2Zd/DcLVNtRWTFQO110zdQvyvy+euPsomr//77h9y7uHrvGTHNXki/Bbmj/PvP39KJq74QXcCR1rk7ffU+MAyAeQvC1VSSAjagTl69R1AjsFsCTKB2hmrw3Fk/YwNyF4r63WVg9q+fsRGYMyANahdzrZ3HrxLUBVRjqqUAKUSBeoEmbDx4geYDEGv3nU1uXvDq/WcgO8jJePeJq/hjENgR2HjwfLCzCaSHlNa6EDIYQY8hHWAa8CuctHznKRVZMXUFiXV78Vl84MwNYAfLyURj1e7TQF0nLt8jw0byR/OAeatlzub5Gw+rK0jO2XA42NmYm5Mda2Uxfc0BSWH+wJIpj16QP5pH6bAjsAJ8Cq6cIqtmAVOhkowopF44fO4WsDh7+vL9uZuPrt17Rnl7lHF00nbUoaMOHXXoqENHHTrqUHIAQIABADFaB7UK2ikiAAAAAElFTkSuQmCC',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'I am a teen parent and I want to establish parental rights over my child.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '1701916a-d8ce-4d2d-8d22-8397c30abdd3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '311K - FAM Teen Parents Custody/Visit',
          'format' => NULL,
          'safe_value' => '311K - FAM Teen Parents Custody/Visit',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'I want to know about other benefits I may qualify for.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '171f929d-f811-4b98-b850-b93f2cef80e8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'de934714-cdfb-4476-9a1e-5c3d1c3d6896',
    ),
  );
  $terms[] = array(
    'name' => 'I was in a union.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '1822466e-84e6-409d-8b4b-386a07209e98',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ccaaba92-32c5-437d-958e-3c6b04895208',
    ),
  );
  $terms[] = array(
    'name' => 'I need a tax abatement from the town/city based on my inabiltiy to pay.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '18367075-e181-40fd-a0ad-76e15674d2c0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9349aebc-f621-4eb7-92a1-d8e3a263185f',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with Food Stamps.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-6',
    'uuid' => '191f6939-3bf2-43c7-be49-9a2fe6495ffa',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord has increased my rent.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-5',
    'uuid' => '1a8c7735-7d99-4c45-b6b1-8a2560978121',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with a family matter (such as divorce or child support).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '1adacbde-e647-4ac1-9381-62c77c50132f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    ),
  );
  $terms[] = array(
    'name' => 'I want to get guardianship over a child who already lives with me.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '1cf9e048-b3ac-46cb-bc3a-5ed901fe0390',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8dc89d9d-e5da-443a-a3ab-d5049b8e6280',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for financial help from my town or city.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '1e24bfe7-1c0a-4977-95be-ae76ece0c43d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with a loan, "rent to own" loan, or home mortgage.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '201ece9f-b22c-4e8e-ab07-c03e7c1dc53e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    ),
  );
  $terms[] = array(
    'name' => 'I have a serious medical condition, my family member has a medical condition,  I am having or adopting a child, donating an organ, or have a death in the family.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '205507c5-ab97-4566-a4e3-055b8b700e9d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4e783cd4-06d6-47cf-9324-5da03a344294',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with LIHEAP (Fuel Assistance).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '20d8f25e-49de-42f3-aca2-75333b3745b0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8ea3018d-2d60-49ab-943c-49d53d2fae0d',
    ),
  );
  $terms[] = array(
    'name' => 'I have lost my drivers\' license.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '228b0a63-da88-4fe1-9e79-9be6a6be7690',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'acba75bd-7ecf-4a3a-90b0-0872149ef740',
    ),
  );
  $terms[] = array(
    'name' => 'I have a question or problem regarding my employer-provided health benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '22a7cf63-654b-43af-85be-97ff3c1e2d53',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '86a0f533-382a-4e9f-bdd3-03a5ee408067',
    ),
  );
  $terms[] = array(
    'name' => 'I am in jail or prison and have complaints about conditions or other violations of my rights.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '2315c257-368c-4142-a313-3be587598ba2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f0020f81-3f84-42d3-9928-d3def15acac2',
    ),
  );
  $terms[] = array(
    'name' => 'Someone in the government has violated my Constitutional rights.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '2391ff3e-3792-4a5f-a8b6-15722faf504e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'I have another health-care-related legal problem that I don\'t see here.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '23972457-25c4-47f7-b381-1e19a8b2e08d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'I don\'t plan to keep my home, but I need legal help with figuring out what to do.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '24aaf71c-532e-4315-bc27-703c402e74ac',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '13ccb7d2-ece5-4b19-a02a-129a9292dee6',
    ),
  );
  $terms[] = array(
    'name' => 'I have another foreclosure related problem.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '24f09d2a-dd76-4006-a33a-380ae7937f9b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '671 - HOU Home Mortgage Foreclosure',
          'format' => NULL,
          'safe_value' => '671 - HOU Home Mortgage Foreclosure',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'cd2f0b1b-ed39-4248-b5a4-23ddacf6099d',
    ),
  );
  $terms[] = array(
    'name' => 'I rent my home or apartment.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-4',
    'uuid' => '24fb4aa7-08e1-467c-9668-bc32d9312ad5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7501a644-65bd-4e23-82af-86857bba181c',
    ),
  );
  $terms[] = array(
    'name' => 'The IRS has sent me a notice that I owe them money.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '25091707-9f10-444b-8a11-ba3201b3a45c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '241 - TAX Federal/Federal & State Taxes',
          'format' => NULL,
          'safe_value' => '241 - TAX Federal/Federal &amp; State Taxes',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad7cb45a-033e-467c-936a-09bcfad3e732',
    ),
  );
  $terms[] = array(
    'name' => 'I need help notifying creditors and my accounts that I am deploying.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '261f25b3-c569-492e-8c3d-36c4262480f0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5afb78bd-fc4d-4555-bd52-3dac7a9146a3',
    ),
  );
  $terms[] = array(
    'name' => 'I have another issue with getting medical services through MaineCare.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '26d99a62-1beb-4fbf-9e8e-928062b546e2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '512 - HEA MaineCare Adult Elig - Med',
          'format' => NULL,
          'safe_value' => '512 - HEA MaineCare Adult Elig - Med',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    ),
  );
  $terms[] = array(
    'name' => 'I was fired because I missed work.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '27d8719c-f29d-4cd9-b784-cf600608e38d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '66b0e165-af42-404e-a74a-aea285e61456',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has reduced or cut off my TANF benefits.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '28673f47-5fc9-43bc-8bba-1ee2ca58ab9c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '712 - TANF Eligibility',
          'format' => NULL,
          'safe_value' => '712 - TANF Eligibility',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3d963d5e-247f-4bbd-b000-48e6df3b917f',
    ),
  );
  $terms[] = array(
    'name' => 'I have applied for rental assistance (such as Section 8 voucher, public housing, Rural Housing (formerly FmHA)) but was denied.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '292340e4-c714-48b0-ab24-54cb3f203816',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '646 - PUBLIC Admission',
          'format' => NULL,
          'safe_value' => '646 - PUBLIC Admission',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6d39bcdb-2d69-4188-8cfc-11024794536a',
    ),
  );
  $terms[] = array(
    'name' => 'I am a veteran; I served in the US military.  Or a member of my household served in the military/is a veteran.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '57d27a87-3995-436e-ab1f-91ed08296c9f',
    ),
  );
  $terms[] = array(
    'name' => 'I think that the provider has committed malpractice.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '298989c4-75d5-4cd2-8e14-557245de56d9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '07c63bd5-2464-4430-a3a9-8a49c64e5765',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS told me my TANF will end because I\'ve been on TANF for 60 months.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '2ae284a8-7959-493a-9865-76ff5f535dd0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '712 - TANF Eligibility',
          'format' => NULL,
          'safe_value' => '712 - TANF Eligibility',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3d963d5e-247f-4bbd-b000-48e6df3b917f',
    ),
  );
  $terms[] = array(
    'name' => 'I lost my drivers\' license because I owe child support.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '2b99e3d7-ef71-4d4b-9662-9be2635ba030',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '228b0a63-da88-4fe1-9e79-9be6a6be7690',
    ),
  );
  $terms[] = array(
    'name' => 'I am an agricultural worker (such as blueberries, apples, broccoli), and I have a work-related issue.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => '2cba87e2-d240-4c8a-9b8d-c61886f8ac7a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '261 - EMP Agricult Wrkr - not wage/FLSA',
          'format' => NULL,
          'safe_value' => '261 - EMP Agricult Wrkr - not wage/FLSA',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '8d52f8eb-4abb-4ac0-8e43-c6f0a3d0b35a',
        ),
      ),
    ),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'I have another school-related problem.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '2cce34b5-68ef-48e7-a459-5e5c9804d532',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '199 - EDU Other Education',
          'format' => NULL,
          'safe_value' => '199 - EDU Other Education',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'I was not drug tested, but my employer fired me because I have a history of drug addiction. I do not currently use illegal drugs.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '2d470a0d-9924-4b26-b2bf-ed2d23867058',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '299A - EMP Wrongful Discharge',
          'format' => NULL,
          'safe_value' => '299A - EMP Wrongful Discharge',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c2c2c551-00e7-41b2-9b1a-d8f84a7ea0af',
    ),
  );
  $terms[] = array(
    'name' => 'I am unhappy with my child\'s current IEP.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => '2d6ed76d-28c2-4bab-90b8-f8509f5730a5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '132 - EDU Programming',
          'format' => NULL,
          'safe_value' => '132 - EDU Programming',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '04882722-da8d-4136-9ece-55120acf9467',
    ),
  );
  $terms[] = array(
    'name' => 'I need other information about affordable health care options.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '2d98ebf2-da34-41d5-8487-3f504d4beda2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4120096d-a572-4152-9528-32b2a6d0187c',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with VA benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '2dec907d-f540-4f0c-b75d-f72d63278ef2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    ),
  );
  $terms[] = array(
    'name' => 'I need information about the Earned Income Tax Credit.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '2f0b6eca-862c-4e5b-a6d2-b37763a40235',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4be96cfc-06c1-4050-bbb9-ba7942aa4b7d',
    ),
  );
  $terms[] = array(
    'name' => 'I believe that I have been illegally discriminated against because of my disability.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '2f2084c2-4445-45db-a003-1bd32c41531e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '841 - IND Disability Rights',
          'format' => NULL,
          'safe_value' => '841 - IND Disability Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5bad7faa-692f-4a4c-a42e-5d6f4ce3e988',
    ),
  );
  $terms[] = array(
    'name' => 'I am having other issues with my Workers Compensation claim. I think I need legal advice.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '2f4ef8e6-fb34-4224-8ec2-951d5eeaff35',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c41c270b-14ba-4897-837f-4ceb4cf831e2',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for a tax abatement but was turned down or didn’t hear back from the town.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '30009387-53c3-48c2-ab6e-e6a143214ab2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '623 - HOM Tax Abatements',
          'format' => NULL,
          'safe_value' => '623 - HOM Tax Abatements',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '18367075-e181-40fd-a0ad-76e15674d2c0',
    ),
  );
  $terms[] = array(
    'name' => 'I have applied for MaineCare but haven\'t gotten an answer from DHHS.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '3038b6e2-abcf-4097-96b0-e2ac0a071a31',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '513 - HEA MaineCare Adult Elig - Non-Med',
          'format' => NULL,
          'safe_value' => '513 - HEA MaineCare Adult Elig - Non-Med',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '508ef373-e252-4933-a31e-83198b205e2e',
    ),
  );
  $terms[] = array(
    'name' => 'I need to correct information on my criminal record.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '3049e8df-aa9a-456f-a95e-7241b8708b4d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c63dd1ca-abc4-46b8-929f-3b4fe3b09a81',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with "General Assistance" - help from my town or city.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '30ca0c21-093e-49a0-83b5-043da62b7b2d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'I don\'t have the criminal background check documents.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '315d0762-17af-4881-aa04-ce400aaa331f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '299 - EMP Other Employment',
          'format' => NULL,
          'safe_value' => '299 - EMP Other Employment',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6df29de3-01f5-4dbe-9db4-27c29ba1f409',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with a non-VA benefit program (such as Food Stamps, LIHEAP, or MaineCare).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '316cce4b-b82a-423b-855f-21cdee77ff2c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with utilities (eg. electric, heat, natural gas, phone).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '31a6da4f-a038-412b-af35-a6c39f4e908e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b7770d7c-ed49-4df6-8df6-9bf4a88c3aa5',
    ),
  );
  $terms[] = array(
    'name' => 'I am younger than 18 years old.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-4',
    'uuid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'The policy says that employees are entitled to accrued PTO, sick time or vacation pay.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '33f3d546-1cca-476b-8658-e7b615014e31',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '65af084f-8fdd-4752-8f41-1c810fd07588',
    ),
  );
  $terms[] = array(
    'name' => 'For Kids and Teens',
    'description' => '<p>look here if you are under 18 years old</p>
',
    'format' => '2',
    'weight' => '-6',
    'uuid' => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'kids.png',
          'uri' => 'public://kids.png',
          'filemime' => 'image/png',
          'filesize' => '4141',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => 'bd4aa3ca-fc86-48b7-9ddd-e9509edc6902',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '57',
          'uuid_features_file_data' => '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',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Cash Assistance (Benefits)',
    'description' => 'food stamps, TANF, town help, Social Security, SSI, other financial support programs',
    'format' => '2',
    'weight' => '2',
    'uuid' => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'taxes-icon_0.png',
          'uri' => 'public://taxes-icon_0.png',
          'filemime' => 'image/png',
          'filesize' => '1719',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '675bcdf4-8f3e-47da-b22d-645eed2dd038',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6RTFCODk1MDI0QzhCMTFFMzlCMTVBNEM4NDBFRkFGNTEiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6RTFCODk1MDM0QzhCMTFFMzlCMTVBNEM4NDBFRkFGNTEiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpFMUI4OTUwMDRDOEIxMUUzOUIxNUE0Qzg0MEVGQUY1MSIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpFMUI4OTUwMTRDOEIxMUUzOUIxNUE0Qzg0MEVGQUY1MSIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Pgiwg3UAAAMrSURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoqENHHTrq0FGHkgJYiFd6dXUzrV2jHVpLBYd++vqddk7k5eJgZGSkTohaJrTRzqEnFlYD3UqRQwc2xklw6MDGOAkOHdgYJ8qhtI50i/hWahZPtIh64mN8gKOe+BgnuXjiYGc9u6QOq9S9p6+nrNx35c4TAV4ucWH+7DBHDQVJrCrtUjrffvxCwyqUnZUlws0Me9hcvhdaPn3n8St6qrLFse4Hz92MqJx58OxNrIoj3M2ARmGNdBZmJio49Nyy+tI4D0zxD5+/lfSv/Pfv/+SyqJ7CMHMdpUOzy4X4uMsmrn757hOm+qxQR6BRPJzsmFKc7GzUbJT8/ffv799/cO7ynSfff/7mbaPnZKrZuWC7T8GkmesOAsW/fP+5eOtxXLqQATc2R1PqUGDy8sqbAERvPkDT2d5T10FZmBuULdhYWR48e7NoyzFIWO49dQ1eaPgWTHLN7n35FksYMxGd90lw6K7jV5+8fP/k1ftNhy5ARB69eAcRB/qhMNp1XXeWo4kGRAqo8v///0DGjmNXHj5/C3Tl5sMX6NQeZWFhhuctCAOYOoHki7cfg0qmLt1+Qk5SeEp5tIuZFlDwPxghK2aFaae5Qz2sdAzUZI005P3sDCAishJCEAYwMbTN25pQPw/IdjEHOVRaVAASre6WOsBMpqUk5WdvSKeGM7CIXtqahiziZKpx6+GLOG8rYPa/fOeJroo0UPDB8zdA0gGWBoAF8Lz6RLq28DFBpLv5su0nf/7+3ZwVwMIMitnD528B8zuwrIn1thyArohtSgewwM8Oc0ITFxHg6cgNzu9ZvvXwJT97AzsjtYy2xcxMTJ35ITJigpjmzN90ZP6mo1+//ySjSUpUGn338eu8TUewStkbqy9tSdVXl915/GrP4p2WesoLG5M9rXSxKl6w+SiwfPj3/z8No/7Xrz8EWyfAEvTVu89ZHUtwKfjy7QcNo/74giqqt57gtSjxTTPCDuXj5qRd25n4xi7LQHVCIE0C6kQ9Tbt1o2NPow4ddeioQ0cdOurQUYeOOnTUobQEAAEGAFt9LzEk6rOoAAAAAElFTkSuQmCC',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'I am not able to enroll in school.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '3553fdf6-e952-4dd3-b485-8e1e26f47e6f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '141 - EDU Residency Barriers',
          'format' => NULL,
          'safe_value' => '141 - EDU Residency Barriers',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'I missed work because of my disability.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '35f7ac76-c0bc-468f-8048-baeecc273b29',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '211 - EMP Job Discrimination',
          'format' => NULL,
          'safe_value' => '211 - EMP Job Discrimination',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '27d8719c-f29d-4cd9-b784-cf600608e38d',
    ),
  );
  $terms[] = array(
    'name' => 'The firing DOES NOT relate to my sex, pregnancy, sexual orientation, race, color, disability, religion, age, ancestry, national origin, or reporting unsafe or illegal behavior.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '362c9a93-5d76-436f-ae06-3325087daba1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '13e5ef58-03e7-4903-8ac2-5ed8d01d76f8',
    ),
  );
  $terms[] = array(
    'name' => 'I have been kicked out of school.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '3633bd41-43af-4e9d-87b1-d1f4a5a4a031',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '122A - EDU Expulsion',
          'format' => NULL,
          'safe_value' => '122A - EDU Expulsion',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'The person harassing me is someone else.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '3796ac2a-27c7-4d03-b374-bc4ee4d1d379',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b0dcffab-3413-4ff6-b09b-5cea8f38a7a8',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has reduced or cut off my Food Stamps.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '39665b70-1ebb-48e0-82d4-8118b27d6768',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '731 - SNAP General',
          'format' => NULL,
          'safe_value' => '731 - SNAP General',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '555ee673-8f46-4dc6-a40b-ac4365807b55',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with a divorce, separation or parental rights/paternity case (includes child support).',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => '39d64169-94d4-46cf-ae79-87220c874bbf',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with my ASPIRE benefits.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '39ff4816-65e6-4e63-a955-db231a1b8185',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '718 - TANF ASPIRE',
          'format' => NULL,
          'safe_value' => '718 - TANF ASPIRE',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3d963d5e-247f-4bbd-b000-48e6df3b917f',
    ),
  );
  $terms[] = array(
    'name' => 'I have been charged with a crime.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '3af1eef1-9e5d-48ca-b559-6b228eda3124',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'b401fe9d-9865-48b2-8326-5962c259d514',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '69191465-1d27-4267-8897-75a9f548203c',
    ),
  );
  $terms[] = array(
    'name' => 'I received an eviction notice while my spouse is deployed.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '3b3caa00-8298-4077-87fc-31d8efb5ebb6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '631 - PRIV Eviction',
          'format' => NULL,
          'safe_value' => '631 - PRIV Eviction',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5afb78bd-fc4d-4555-bd52-3dac7a9146a3',
    ),
  );
  $terms[] = array(
    'name' => 'I was not drug tested, but my employer thought that I was using illegal drugs.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '3b5c6981-755b-4996-a069-27a36a58d722',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c2c2c551-00e7-41b2-9b1a-d8f84a7ea0af',
    ),
  );
  $terms[] = array(
    'name' => 'I have discipline problems at school.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '3bb36649-b2ae-4d5a-b2a1-fd3c34a5be00',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '129 - EDU Other Disciplinary Action',
          'format' => NULL,
          'safe_value' => '129 - EDU Other Disciplinary Action',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'I was or am being harassed on the job.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '3bda5ac9-46c2-4ecd-a417-2a450b61cc2f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'I have run away from home and want to access public benefits such as food stamps or TANF.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '3bef5718-7d56-4e66-a25a-0cc6aa2c488e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '432 - JUV Runaway',
          'format' => NULL,
          'safe_value' => '432 - JUV Runaway',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd4cf083f-648e-467f-87d0-f509c3104c45',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has sanctioned me, saying that I have violated program rules.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '3c6dbd76-c14a-4906-815b-fe3270d49320',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '718 - TANF ASPIRE',
          'format' => NULL,
          'safe_value' => '718 - TANF ASPIRE',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '05e8665f-5e85-4773-944b-625b548ae26a',
    ),
  );
  $terms[] = array(
    'name' => 'I currently get TANF but have a problem.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '3d963d5e-247f-4bbd-b000-48e6df3b917f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '119990b0-9a61-4daa-9465-86d3627e80ec',
    ),
  );
  $terms[] = array(
    'name' => 'My employer (not a government agency) has violated my Constitutional rights.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '3db1a4dc-33c0-46bd-bf43-609d26d727a1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '259 - EMP Other Employee Rights',
          'format' => NULL,
          'safe_value' => '259 - EMP Other Employee Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2391ff3e-3792-4a5f-a8b6-15722faf504e',
    ),
  );
  $terms[] = array(
    'name' => 'I was injured by someone else\'s negligence or recklessness (such as a "slip and fall" case or slander).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-5',
    'uuid' => '3e8cf1dd-bca4-4ab6-b2e7-623dfb998c04',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for Food Stamps.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '40bee87a-a5eb-4de8-a59e-7377eba5f852',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '558cd122-db93-4f43-adc9-be37f59ff004',
    ),
  );
  $terms[] = array(
    'name' => 'I have run away from home and want to access my own healthcare.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '40cbad88-89d6-47da-92d5-1c47fb664b2c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '432 - JUV Runaway',
          'format' => NULL,
          'safe_value' => '432 - JUV Runaway',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd4cf083f-648e-467f-87d0-f509c3104c45',
    ),
  );
  $terms[] = array(
    'name' => 'I cannot afford my medical bills and don\'t know where to turn.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '4120096d-a572-4152-9528-32b2a6d0187c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'I have a different problem with TANF.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4123edd3-10d6-415e-ae51-e2a6907ff6fd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '119990b0-9a61-4daa-9465-86d3627e80ec',
    ),
  );
  $terms[] = array(
    'name' => 'I believe that I am being harassed because of my sex, my sexual orientation, my color, national origin, ….',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '41257b27-2eff-4673-988d-7325a69a3e72',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3796ac2a-27c7-4d03-b374-bc4ee4d1d379',
    ),
  );
  $terms[] = array(
    'name' => 'The problem is with my heating bill; I heat with natural gas.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '416626fe-d6e5-48eb-9d14-7c85c553c7fa',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'I am being discriminated against because I’m an American Indian or Native American.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => '419c1cb6-ba15-4476-a3a4-f1b3b0bf4cd3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '851 - IND Civil Rights',
          'format' => NULL,
          'safe_value' => '851 - IND Civil Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    ),
  );
  $terms[] = array(
    'name' => 'I bought the product from an individual.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '42185365-84f3-40ef-b55f-fefa3674be4d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4fdc7f82-1073-4e35-be0d-edfa87d69dfe',
    ),
  );
  $terms[] = array(
    'name' => 'I have abandoned my home because I cannot afford it or threat of foreclosure.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '422d7c61-5b55-43f4-bbf1-6241201140b3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'cd2f0b1b-ed39-4248-b5a4-23ddacf6099d',
    ),
  );
  $terms[] = array(
    'name' => 'I have not contacted the seller.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '42dafd51-ad39-4ca4-9ea5-4c6a8ff28efb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a024519-29d7-4c3c-867a-da32cd3aa63a',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with the Property Tax Fairness Credit (formerly known as the Property Tax and Rent Refund program or the Circuit Breaker program).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '4370cb23-faab-4925-b713-2fd568d2156a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '622 - HOM Property Taxes',
          'format' => NULL,
          'safe_value' => '622 - HOM Property Taxes',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e0292fc9-7c7d-476b-b893-6f7f5b5b49be',
    ),
  );
  $terms[] = array(
    'name' => 'I was a permanent employee of local or state government.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '43cf7f30-fa26-4b8a-86d1-b30a2b5c94a9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ccaaba92-32c5-437d-958e-3c6b04895208',
    ),
  );
  $terms[] = array(
    'name' => 'I have another legal problem relating to my mobile home.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '4418b0d0-4d41-4dce-b542-17f788c787bd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8d0d7bc5-f165-445c-a81e-ea6a0336db31',
    ),
  );
  $terms[] = array(
    'name' => 'I believe that I was fired because of my sex, pregnancy, sexual orientation, race, color, disability, religion, age, ancestry, or national origin.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '44773640-bbcf-4d01-95b6-2397f47e8bc3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '66b0e165-af42-404e-a74a-aea285e61456',
    ),
  );
  $terms[] = array(
    'name' => 'Consumer/Debt',
    'description' => 'problems with things you bought, bankruptcy, credit, identity theft ',
    'format' => '2',
    'weight' => '1',
    'uuid' => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'consumer-icon_0.png',
          'uri' => 'public://consumer-icon_0.png',
          'filemime' => 'image/png',
          'filesize' => '1880',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '12131fbe-d846-44bc-b83d-fa314375db13',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6MUEwNkRCQjI0QzgyMTFFM0JCMjFDMTg3NjY2MTQzN0IiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6MUEwNkRCQjM0QzgyMTFFM0JCMjFDMTg3NjY2MTQzN0IiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDoxQTA2REJCMDRDODIxMUUzQkIyMUMxODc2NjYxNDM3QiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDoxQTA2REJCMTRDODIxMUUzQkIyMUMxODc2NjYxNDM3QiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Po/4uesAAAPMSURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoqEMHF2AWVLOi3BRGRsb6NL/GdP9///9fvPUYIpgV6thTGC4swHP80t3BEqKqcuJhrqaigrwlMe7srCxAEX4eTqBDRQR4kvxspEUFBotDLXSUIIw7j1/9/P0HyPj6/dfT1x8gglb6KoMi6sPdTKuSvK/df946d8vkFXt//fkLFASmgS2HL166/URSRACo4MXbj9fvPx9IhwIdUZviC3RlStMCoFMgroSAH79+33v6eveJq+Y6ShFuZhS6lSKHIrvy09fvWNX8+v1n1/GrlrrKFIYr+Q4lxpVwt+48fsVKTxmY4ch2K5kOJd6VcLfuALpVX4Vst5LjUFJdiRSuV8l2K8kOJc+VEAAsuXaduGqtrxrqYkKqW1kIqjDVUtBTk4WwgQV4rJclsOg5celuqKsJeYn7+OW7avLiTRkByjJi7z59hQheuvX49LUHFDnUxlA1JcAOJRYYGZMDbCkvwxN8reHsORsO4XfokGmUEA7Rl28/Xb33jNbuANpCoN1D5EgJJzsbKwszLZz4+8/f7z9/USFE4ekpJ9yJFg6duHzPrHUHqdZ62nv6Oo0ifc/Ja9RJoxBw6+GLxy/fyYoLoYl3LtiuICUCZDx49sbHVm/yyn29hWFBpVPXdWcX96/KDXfacvgSXEF5giea9vtPXwMbLlRuj+49hSVQ33788vnbdyACMoDl+cu3H4Gl7JOX74EkkA0UQVaAqX03ccFJBYdSCIhPUSQ49MLNR+8+fqWiK4G16NW7z6jvUGBs7jtzg5rBeer6////qVbgoxp9LcTZGFnEXFdJXIgPyBDk4xYR4HWz1AYWt8A2B5AEsoEiyArQ8/upa8RbTZpDT1y+9/X7T25OdriInooMF5gLdI0gL5eVngorM7O7pQ6QBLKBIsgKkI16//nb2WsPadULBbYpD5+/jSwye/2h7UcvARGQcfvxy4aZG7/9/JXSvABIAtlAEWQFyBoPnLnx998/GnaX95ISX/jKeRLLEJIdCgzR30hdTfLAtx+/jl+8Q1uHfv7249SV+xQ69PD5W5BxCtqOlOyhOPb3kF53MJIxISYqyLtvZikTIyOQ/eTVew42VshwgxAf9/M3H4A1+40HLzQUJICVu6SIALCzAVcgIyYIyZF2KZ3AmKFywxkTvH7/+ey1B6baikA2xG44AHaDgKS2khSczcXBhpnKSXUlmQ4Fgqqp6zwsdRiZGElrI//+++3Hzz1ktRkYR+dCRx066tBRh446dNShow4d1g4FCDAAS2f6/R9YSmQAAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'We don’t get along.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4591dba8-b8eb-4359-830a-51ca0f9a5fa9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '97eca8ab-4131-43e2-90bc-2e1064075c2c',
    ),
  );
  $terms[] = array(
    'name' => 'I live in a mobile home park and my landlord is shutting down the park.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '4595ad34-1b70-45cc-88ca-a909a2b72672',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '651 - MOBILE Eviction - Home Rental',
          'format' => NULL,
          'safe_value' => '651 - MOBILE Eviction - Home Rental',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f35268de-da45-48e4-9a9b-8af3959f47e5',
    ),
  );
  $terms[] = array(
    'name' => 'Education',
    'description' => 'special education, IEP\'s, truancy, expulsion, bullying, adult programs, student loans',
    'format' => '2',
    'weight' => '0',
    'uuid' => '45bbeff5-0de4-493d-bd09-8000b96af17a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'education-icon.png',
          'uri' => 'public://education-icon.png',
          'filemime' => 'image/png',
          'filesize' => '1946',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '5a57eae3-aa0e-4b9c-8453-5ccba1d0a583',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6RDNEQzU3RDY0QzgyMTFFMzk0MDZERjJBOTJEM0IyRUMiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6RDNEQzU3RDc0QzgyMTFFMzk0MDZERjJBOTJEM0IyRUMiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpEM0RDNTdENDRDODIxMUUzOTQwNkRGMkE5MkQzQjJFQyIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpEM0RDNTdENTRDODIxMUUzOTQwNkRGMkE5MkQzQjJFQyIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PgKFPMEAAAQOSURBVHja7JlJTBNhFMc73RdaloIsskgRRWihilqgWKPBIBYwRjRiXA9qvOjF6MklMTHxYEw8iImKxo0EMIgLBNCC7ALKJhTKWlpZQ6ss3YDi0yYeoJaStliT78vkO8w38+bX9+a99/+mGCf5Au5/GHjcfzIQKAJFoAgUgSJQBIpAEehyBtG+5ggEfMLW8JOpwmmt4W6O5LNU7nSgDBpl/87oo+JYPy8305kYHqfuax/g1rf3224fs13h+7Bdj+yJSUvYzKRTzV4AoIAL0P8MNILjdzxFmBgbQSQQlrwYXoN7uaXVLT0rB4rHMFH0+uPiuK3c4OXe29Q5cDe3tKqp27GgFBIxdTsfvBjs52lLHJtliozcsopGmf1BPVwZh3cLDiUK3Jl0e+Vfa7cScMu/yObn5+0AGuK/6lhyXIooCtzpiALZ1juYkVNa9rnTMq4l0NjIECg3oo3rMAxzdD2X9g1l5JZK6jv+hmsedHcc99Q+UdgaXysfM2c0tnYpIa+buxQDwyqt3kCnUjzdXEJWewl4HAGXQ6eSrbHT2T8MqSapkxoX4ZqPZkN7f5AP253J8GazLJtWjqizij4VVLaMqicXLMnkuOrm7qcFNS40inhb5ImU+EAfDwum9DOzsoER1Y9pozmnWgo9AY/fsSUsPVEAPWbxKnjuTtb74to2cKepM4UH+wb4eLAYNPAftNCJaa18aBxiCg6GC0hEApg6n55ApZAWmOr7NpZd0pD/sfHHlNamrG/Luf68sBYKk6n3aHSGey/Lnrytnpmdg1KfJOSmivhQU82WfcPMbE1rz+uPTSW17fCTOKu9bp5LC+f4mZZKPrVnl9Q3WNFjrQWNOHAZ/AS5v3F90O0XxSPjE3Ae9MelE0l/mrvlAd69kfmusqmLTCLCXQNDKnDh90mNPeuoCXTByaunUw/u2rKs1IaMfvSm6tbTohXVo8ul/OUVDDuQsNlRwtnX0xXmNb6euH86lga9fnYfzHcupjs7qHJUbUoFZ9+KPMgrhxfr5uNCs6tQqj7USVu6FD3KMcWIakqjn9bqoQyBMIAq4cZigM4K8fcS8kOjNwThbWjFS4OK4yNhTozlPsyvWLBUWN16JeMVsJptM3CoJzVQzCX10vt55QHeHplXTzIZVEeFHrofzMmiqMX9nUomwW7OyifRqGQikTA3Z1zprUg8P/Tamb1uTFpVc3dbz2CvcgwatUann5jSQb0kkQgQerarC2iGtQGrIO68UP+KL7Jbz4p7v42t9J4JXsQkIS9FxN8UFkj+i1oFF3bIh8saOt5VttiSkZhd/mcCwQFJEwiCi0Wn/VZ0Wp1BPaFRjKrkg+M6w4yz7OtBnYBCgwN90kGgCBSBIlAEikARKAJ1jvFTgAEANneu96eSqZ8AAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'The bank is foreclosing on my home, or I am being threatened with foreclosure.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => '46e005d8-954c-4a6a-a712-a3f2a6f3ff85',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'cd2f0b1b-ed39-4248-b5a4-23ddacf6099d',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '201ece9f-b22c-4e8e-ab07-c03e7c1dc53e',
    ),
  );
  $terms[] = array(
    'name' => 'I have issues with another government-funded training program.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '471bbd2f-da44-4272-ad25-897fbcc9b8f3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '151 - EDU Vocational Education',
          'format' => NULL,
          'safe_value' => '151 - EDU Vocational Education',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e36b4eb3-ee6b-438b-88df-523f064c6dde',
    ),
  );
  $terms[] = array(
    'name' => 'I want to get guardianship over a child who currently lives with someone else.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '4867e7f6-e2b8-4a61-88c1-25017602ad2e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8dc89d9d-e5da-443a-a3ab-d5049b8e6280',
    ),
  );
  $terms[] = array(
    'name' => 'I need help in dealing with the juvenile justice system.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '491e7290-8474-458d-9f4c-2c5897540f7b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'f39a9ae3-9929-4362-95d8-3e770f66eecc',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'My child is being discriminated against at school based on her race, gender or disability.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '4947911b-4a7b-4ccb-832f-41dad287b3e6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '192 - EDU Discrimination (race, etc)',
          'format' => NULL,
          'safe_value' => '192 - EDU Discrimination (race, etc)',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'I have a different issue concerning adoption or guardianship of a minor.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '49504748-0af5-4742-85fa-21ccf6555f6a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8dc89d9d-e5da-443a-a3ab-d5049b8e6280',
    ),
  );
  $terms[] = array(
    'name' => 'Employer’s policy says employees are NOT entitled to accrued PTO, sick time or vacation pay.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '49df349f-9fe6-428e-821b-5945b17fed67',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '221 - EMP Wage Claim/Fair Labor Std Act',
          'format' => NULL,
          'safe_value' => '221 - EMP Wage Claim/Fair Labor Std Act',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '65af084f-8fdd-4752-8f41-1c810fd07588',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem paying my home utilities - water, electric, heat.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '49f0113e-7c11-4719-8742-0e3e4c3b8c2a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '31a6da4f-a038-412b-af35-a6c39f4e908e',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b5d4068f-bd35-4bd1-bca9-4592203ea2dc',
    ),
  );
  $terms[] = array(
    'name' => 'I bought the product from a company.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4a024519-29d7-4c3c-867a-da32cd3aa63a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4fdc7f82-1073-4e35-be0d-edfa87d69dfe',
    ),
  );
  $terms[] = array(
    'name' => 'Employment',
    'description' => 'pay issues, work conditions, lay-offs, severance, retirement benefits ',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'employment.png',
          'uri' => 'public://employment.png',
          'filemime' => 'image/png',
          'filesize' => '3651',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '261f297b-685b-464a-a4ae-c0d6866c9594',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '50',
          'uuid_features_file_data' => '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',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'My legal issue is not directly related to the fact that I have a disability (for example, I need a divorce or need to apply for food stamps).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4b7d071a-0c61-4cd6-93e0-00ee13a422a4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c556b483-3dbf-42e7-9337-0cc0a0a98d4c',
    ),
  );
  $terms[] = array(
    'name' => 'I have a question or problem around the Earned Income Tax Credit.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '4be96cfc-06c1-4050-bbb9-ba7942aa4b7d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'bad14cf3-9a7e-4e33-a94c-7685c0079e59',
    ),
  );
  $terms[] = array(
    'name' => 'I have a child who is being denied residential treatment.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '4c55dbb4-aad7-4b67-9801-af7b4549b495',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '531 - HEA MaineCare Child Service',
          'format' => NULL,
          'safe_value' => '531 - HEA MaineCare Child Service',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '45bbeff5-0de4-493d-bd09-8000b96af17a',
    ),
  );
  $terms[] = array(
    'name' => 'My housing is unsafe or unhealthy (such as no heat, leaking roof, dangerous electrical).',
    'description' => '',
    'format' => '2',
    'weight' => '-6',
    'uuid' => '4c7e3484-2650-41ce-939a-d18691ced996',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '632 - PRIV Warranty of Habitability',
          'format' => NULL,
          'safe_value' => '632 - PRIV Warranty of Habitability',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I need to get a child support order.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4d35cfca-0235-481c-afd4-b13c43758e9b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f0ad725c-b9cc-46f3-ac41-dd66d9924f2d',
    ),
  );
  $terms[] = array(
    'name' => 'I am disabled and need a "reasonable accommodation" (such as a service animal, wheelchair access or other changes to my rental).',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '4dbc640d-28ac-424f-b1e6-d1564e88a2e8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '611RA - FEDSUB Reasonable Accommodation',
          'format' => NULL,
          'safe_value' => '611RA - FEDSUB Reasonable Accommodation',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f038138e-92ac-4103-a846-4a8dd46b6547',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for TANF.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '4e3320ec-c422-4513-9156-b3773c240bee',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9d2eba9c-cc98-4569-b093-f8a1172e9ba4',
    ),
  );
  $terms[] = array(
    'name' => 'I need time off from work or a schedule change.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-4',
    'uuid' => '4e783cd4-06d6-47cf-9324-5da03a344294',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'I have another type of legal problem that stems from my disability (such as the need to access housing, education, or a public place).',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '4e969bec-54c3-4d82-b27e-e8e8462109d6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '841 - IND Disability Rights',
          'format' => NULL,
          'safe_value' => '841 - IND Disability Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5bad7faa-692f-4a4c-a42e-5d6f4ce3e988',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem with Food Stamps.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => '4f78a368-d611-4ad2-a6d1-042c3312b076',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '555ee673-8f46-4dc6-a40b-ac4365807b55',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with another kind of VA benefit.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4faded7f-72a1-4b69-ba7f-564f2b160b60',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2dec907d-f540-4f0c-b75d-f72d63278ef2',
    ),
  );
  $terms[] = array(
    'name' => 'I am being harassed for other reasons (such as bullying or neighbor dispute).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '4fcb65f7-1345-4407-b96a-be977cb4c347',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3796ac2a-27c7-4d03-b374-bc4ee4d1d379',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with a defective product I bought.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '4fdc7f82-1073-4e35-be0d-edfa87d69dfe',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    ),
  );
  $terms[] = array(
    'name' => 'I am declaring bankruptcy and need legal help.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '5021135e-115f-4721-bb1e-fcdc13983d89',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for MaineCare or I\'m having a problem with my MaineCare application',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '508ef373-e252-4933-a31e-83198b205e2e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd42d6a48-e52b-4d30-928e-ba27bbc276ea',
    ),
  );
  $terms[] = array(
    'name' => 'I have another legal issue that relates to my status as a veteran (such as discharge status, GI Bill, or special property tax exemption).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '518ca523-9f8f-42b3-9bbb-08994b25cf9d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2972dc0c-3c83-4d38-ade3-f27231da1873',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with planning for medical emergencies or  long term care.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '51f9d31f-ab3e-46c5-a9e6-f8483552b570',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'My mobile home is not in a mobile home park, and my problem is with the land owner.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '5290eb9a-1b0b-4e91-b0ad-77644b11bf29',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8d0d7bc5-f165-445c-a81e-ea6a0336db31',
    ),
  );
  $terms[] = array(
    'name' => 'I immigrated to the U.S. from another country.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '52f72c5f-b8bb-4ee1-80ef-42986fc1ea34',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'DHHS says that I am "substantiated" or "indicated" for neglect or abuse of a child.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '53467ab1-c9d5-4c87-8016-e79c61a95c63',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd36972e9-6cc2-44d8-8510-21475f663daf',
    ),
  );
  $terms[] = array(
    'name' => 'I have another issue or question about DHHS child protection services.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '53b61667-05b3-4583-8967-8a099775a187',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd52e5dc1-9cd0-476b-b0e2-3c68bebe6c7c',
    ),
  );
  $terms[] = array(
    'name' => 'I am having another type of problem with the group home or shelter.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '550829c7-6ef1-4688-878a-e0424d7e92d2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'cbad4abf-0a53-409c-b29e-383f0558c0dd',
    ),
  );
  $terms[] = array(
    'name' => 'I have another Food Stamps problem.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '555ee673-8f46-4dc6-a40b-ac4365807b55',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '191f6939-3bf2-43c7-be49-9a2fe6495ffa',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for Food Stamps or I\'m having a problem with my application.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '558cd122-db93-4f43-adc9-be37f59ff004',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '191f6939-3bf2-43c7-be49-9a2fe6495ffa',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with Social Security Retirement benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '5734df54-b0fa-4d83-9d10-215dd998cbb9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'eb02b3f2-6c2c-469d-9f0e-001edddbbfde',
    ),
  );
  $terms[] = array(
    'name' => 'Military and Veteran Issues',
    'description' => 'deployment-related issues, discharge status, VA benefits and more',
    'format' => '2',
    'weight' => '-7',
    'uuid' => '57d27a87-3995-436e-ab1f-91ed08296c9f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'veterans.png',
          'uri' => 'public://veterans_0.png',
          'filemime' => 'image/png',
          'filesize' => '52359',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '01cbbf9b-9f87-4448-bff2-2d8e3ed4892d',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '50',
          'uuid_features_file_data' => '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P1Yv7JdjXv+3IfchEHsZdcy1yrRVptnzGtm3/xNBnNH9kf9HZT5Hff4/xf8Zf/b+kHbinL0Zjvgz/8lYE35qvfqcl3sC+HpUp/RBt09ez/LKsNE+E/ezP3OdeY/KfK628H/fRymfUKY8LzHWMX4yltGe14afUi/CGDf4jwAb074Qc233fx9zco/ymP/5fyLzKPX73f+zMp+rY/7PuR079H6SdS318Sl9g7+Iyzy2Vfgxu2cYtuT9OudhxnDiYue0NXud+DP3KI+Vg39r8SFtJ23KntnI/6Myn/MuyH5b1il9R9/OumKP0VhF3Eyv59f92fvBmnDCluqVYdSDuaT7N+fy0TcYz/fnRnn1MNpA34tMGxM/856Vufe1S2hpvUA9vvS/UkoppZRSSimllFJKXU07EREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREREZE75B+Hl45q2TuOnAAAAVNta0JU+s7K/gB/pYUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHic7dbhaYNgFIZRB3ERB3EQF3EQB3ERB7G8gQu3piH/ignngUObT/vrTWzOU5IkSZIkSZIkSZIkSZIkSZIkSR/RcRznvu9P5znLtXf3v7pP929d13Mcx3OapsfP7Bj9LPfUvXUWy7I8XscwDH++h3TvsmOVfbNhdq3N+z21f9U3v/6N7l+263tWOeuf5XqdffvG2b+6XtP9y3O+71//1+d5fto/1+z/fWXbeu7X79u2/frM9+e//b+v+h7X96v3QK7Vd/ucRdWfHddrkiRJkiRJkiRJ+vcGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD4QD8K+ay4UtoqZgAABXpta0JU+s7K/gB/tU0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHic7dvbT9tVAMDxPpnog4BLNGXqYODiJNEYE9tN3IvRLNM/wGgyswcyEw3qYnxwCxsTJpu4MHUDBEEYg6FVxDIu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TTpEb2N1bWVudElEPnhtcC5kaWQ6NTlGODkzMjg0QjA3MTFFNDhCQ0JEQzYwNTIxMzg2NEE8L3htcE1NOkRvY3VtZW50SUQ+CiAgICAgICAgIDx4bXBNTTpJbnN0YW5jZUlEPnhtcC5paWQ6NTlGODkzMjc0QjA3MTFFNDhCQ0JEQzYwNTIxMzg2NEE8L3htcE1NOkluc3RhbmNlSUQ+CiAgICAgICAgIDx4bXBNTTpEZXJpdmVkRnJvbSByZGY6cGFyc2VUeXBlPSJSZXNvdXJjZSI+CiAgICAgICAgICAgIDxzdFJlZjppbnN0YW5jZUlEPnhtcC5paWQ6NEUxNkU3RTMwMjRCRTQxMUFFNjdGMUVDQjQyMjRBNTY8L3N0UmVmOmluc3RhbmNlSUQ+CiAgICAgICAgICAgIDxzdFJlZjpkb2N1bWVudElEPnhtcC5kaWQ6MzVBMkNFMzBEMDg1RTIxMTgyODRGQzRFNjkxQjM4NUY8L3N0UmVmOmRvY3VtZW50SUQ+CiAgICAgICAgIDwveG1wTU06RGVyaXZlZEZyb20+CiAgICAgIDwvcmRmOkRlc2NyaXB0aW9uPgogICAgICA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIgogICAgICAgICAgICB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iPgogICAgICAgICA8eG1wOkNyZWF0b3JUb29sPkFkb2JlIEZpcmV3b3JrcyBDUzUgMTEuMC4xLjcgV2luZG93czwveG1wOkNyZWF0b3JUb29sPgogICAgICAgICA8eG1wOkNyZWF0ZURhdGU+MjAxNS0wNC0yMlQxNzo1MTowNFo8L3htcDpDcmVhdGVEYXRlPgogICAgICAgICA8eG1wOk1vZGlmeURhdGU+MjAxNS0wNC0yMlQxNzo1MTowNFo8L3htcDpNb2RpZnlEYXRlPgogICAgICA8L3JkZjpEZXNjcmlwdGlvbj4KICAgICAgPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIKICAgICAgICAgICAgeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIj4KICAgICAgICAgPGRjOmZvcm1hdD5pbWFnZS9wbmc8L2RjOmZvcm1hdD4KICAgICAgPC9yZGY6RGVzY3JpcHRpb24+CiAgIDwvcmRmOlJERj4KPC94OnhtcG1ldGE+CiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgCjw/eHBhY2tldCBlbmQ9InciPz7I6lCZAAAF4klEQVRoge2ae0xTVxzHf+e2995Wby2P2iKwNjClPFRgTIgoDAwqElzwsTHNnFsWXDBOE/Ywm2ZTJ3OLbm7Z3BRnjHHqxgbLHCBmOOlYrCCdDmmmkwwRqHVFV159t3d/TAxqHee2tzoMn6R/9Dx+5/u993fOubenKDq/hIWHGOJBCwg0YwZHO2MGRzsPvUFhIIMzfRlbTPaWZMeAQe0c7I0AAECIcAEgNyIELkQInARFDQpFYpuAptysR2Qi2AmdQZTKaJVqN/ChIaAGTQ7d7K5Tm+cQBH6imM1mV2tr62/f/ZzdWFPTf8IR3PymPxoEwTEzN/kT4F6IzGlbj+7JzlUoFAynfiIRoVQqw+dnxEQmTjGLaqul+12i7kxfdQRsDro8NjIyMjLUnxjx8fFJvc7OSf7ECJhBUjDOpdfr9f7EKD92/jo90fCiPzECZtAq1W5Y8aq+XqfTXfalv0ajOb2rrGefvzoCuk0g2cV1y9fqv25razNz6edwONjl65su8bGSBmQVFffOLL3h1CcBSw5ebVy5zW5vfYGTKKEQsWCT8KGFd4MOk7Ls8MePLE5IyI2RSCRb6urqvkpISJBzieHxeFgAws2HHl5T1G6K+KLuQO7StLS0OIZhBNXV1eE5OTk7DQaDlUuc/v5+N4VCDHxo4s2gtYepbTiyqFCtVocAAHR2dlpe/vzES9H5JcePaZqaucS6du1ar5Sa9DcfunhJUWuPuP732pK5UqlUMFR2vKG5GQAyAQBIAYG4xKvXGV0DExre4kOb33fQagotP/f92vTh5nQ6Xfu7hzTdAADAshWRMobTfDL22K77q2sIvwzS5hmlNbvz0uVyOTVU1tXVZVm6cb8GEYJltwYhCBI3pkajafzm275Kf3QNx6cUtZnCDpYUJWfGTXJMjImJCR9ed/jYqQZCSD9/qwChJVf+6vsFN3alptdpC2rc6Isub3A2aDUpvjxdXrhEqVSOA4BVQ+Xt7e395T+e0ZYdPT0A6PYpZ7G7XLjxY6MnTK46w1XVveGUorR5Rmn5jvT4m+ZuQ9PUcq7sh8Z5gNCSO+u2Haj9o6OjYwBnjOJns8JKns6/ajXJDy1Oz24Sm2e+w0XjnXB6XbL2Cy9sfT0vj6Kou1bFpKmxKtI1cFKrv/IrIBQ/vI4g6ctvry6clZqaGqxQKB6jafo/L2xqYpRkzYoZ0xZkxUfm5zCPB42XmVq0sk/EjkdPOuiOLFy9ABzuoKTvic37tsSFMQxzVx+j0Wirqqp6b/uR+it3dWTZij+rPlwBADTLsgaLxeLEGY+maQQAoFQqx699bk5Exd5pxTs3SebYTGEHcTUDcJiDZkd3yPTpi+Z7q2tra9Ov23NyCiGkbktP1uM6tGtNrnvyzuJuuVw+YfhWwhW1Wh2iVqszavaERC8tPrvdE3r+NZx+2AadxOXZYWFhtLc6s9lcCQClN79WsB63vejJWbKCzKnz4+LiZLhj4JCYmBixuqin8NPK81jtsQ3ae/vGeytvaWm5unDhwh1ReeumeZy2gd0lBWKFQpGRnJysxI3NlYKs6OBde6d+wIa2vjJSW2yDHqdd7K3caDQ2VldXrwwODk5MSkqKFYvFnB7LfCEqKkqy7KkL8w7/1DpiW2yDrMfjdf6o1eq5KpWqgIM+XpgYSmP93oO/D7KsV4Mqlcpr6gYaAiEs7Vw2+oCnHhcQANa5JheD/6uDUgIhrAuObxD9vwwizIzCNkiQtMV3OfwjFOKdB2CvorQ0/KJWq7UwDBMqEolE5L8IhEIhAQBgtVqdKpWKwcwcvxESCOupCNugWNa/oGh9d6nFeYNxsTaRm3VQLHJTAG4SAACx1ODRz7KzUlJSonwVzQWBAG8V5fQ+aJVqNyAAIG9+7uTspUFTSgqXiL5DCgS8bxMjgtj7t5WQQgIrRUftCS9JPog7SNy/O0hTQn4XGRzeeL/CEKOSBbEsC2wAd02CQPDMqo96QmJDw0dqi8b+yjXKGTM42hkzONp56A3+A53a5BMuNNK8AAAAAElFTkSuQmCC',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '57eb2892-e67e-4e22-8a49-be02ca5909db',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'I am in the military now or have served in the past.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '57eb2892-e67e-4e22-8a49-be02ca5909db',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'I have an issue with the amount of rent I pay.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '5882f1a3-b214-4202-8215-822f9621c9b0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '614 - FEDSUB Rent Increase',
          'format' => NULL,
          'safe_value' => '614 - FEDSUB Rent Increase',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f038138e-92ac-4103-a846-4a8dd46b6547',
    ),
  );
  $terms[] = array(
    'name' => 'I had to quit my job because of harassment by a manager or a co-worker.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '58ac6fd2-954d-41c6-9706-81d95c49fdf6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I have another type of home ownership issue.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '58c24b58-22d9-4ee2-b0f1-62c7e606b56e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '00b8afef-bf42-4520-a1a7-e28f384bfa8c',
    ),
  );
  $terms[] = array(
    'name' => 'I have an issue with VA healthcare.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '58d509c1-4aae-4ebc-ad06-ce5b54f46e76',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2dec907d-f540-4f0c-b75d-f72d63278ef2',
    ),
  );
  $terms[] = array(
    'name' => 'Elder Law Issues',
    'description' => 'legal issues particular to people 60 years and older',
    'format' => '2',
    'weight' => '-12',
    'uuid' => '593149a7-b796-4947-a9ab-7e8ae6d2c237',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'elder.png',
          'uri' => 'public://elder_0.png',
          'filemime' => 'image/png',
          'filesize' => '422',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => 'c0c41281-8e68-4526-9f4e-117020732af5',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '50',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAAyCAYAAAAJHRh4AAAAAXNSR0IArs4c6QAAAAZiS0dEAP8A/wD/oL2nkwAAAAlwSFlzAAALEwAACxMBAJqcGAAAAAd0SU1FB94LBA4hFxmAzJcAAAEmSURBVGje7ZnbDYMgFIaBMAkOwgDWYUzqFH3oMKYDMEg7SVP7UhpDDBwQvJD/PJmIeL5z+QHl6nKdWMUmWOUGQAACEIAABCAAAQhAAAIQgGkmUx98jrf/ddMN3rHT521ej7umjs9pPPbAOwdzzXXcBQuN371EfXBL931wlPkO2YPW6S2cz9qDrsOq7Q0XUlNhbDlSwWN6vEgGLdzaviqdaZljkiVxYYzpapYJFzQkLpSlxPeumCoRJQQmxVKCsouK/srz/Fs11fZmqVRSM6Ha3hyqB62KNt2QRQm5kHoesN2XiRhVPfVpYm32SgcjarNNgbE7HCp4acDsJTrvzdOVaMhp935IGbcIAk/9AVrtgRffZAAIQAACEIAABCAAAQhAAAKwCvsCUbN9+0kwNt4AAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '7d2e841a-3c1a-401b-92f2-652f87c0178f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'I have a different legal issue.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '59539981-8730-4f00-8609-020acbedbc93',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8ec455e1-1737-4ed7-a97a-6896c8fe43e6',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for MaineCare but was denied.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '59b92832-5085-4c02-b414-35ac4dd7281d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '513 - HEA MaineCare Adult Elig - Non-Med',
          'format' => NULL,
          'safe_value' => '513 - HEA MaineCare Adult Elig - Non-Med',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '508ef373-e252-4933-a31e-83198b205e2e',
    ),
  );
  $terms[] = array(
    'name' => 'My legal issue has to do with my family\'s deployment.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '5afb78bd-fc4d-4555-bd52-3dac7a9146a3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'af4345ac-4bac-4986-97f2-e286f653b28d',
    ),
  );
  $terms[] = array(
    'name' => 'I have a legal problem that relates to a physical or mental disability.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '5bad7faa-692f-4a4c-a42e-5d6f4ce3e988',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c556b483-3dbf-42e7-9337-0cc0a0a98d4c',
    ),
  );
  $terms[] = array(
    'name' => 'I have been sued in Small Claims Court for some other kind of debt.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '5bf6b146-dd9f-4d18-a36d-8f3892e500e4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'I don\'t think DHHS is giving me the right amount of Food Stamps.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '5c19bbd3-7381-4335-9ef0-131350b23cd1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '731 - SNAP General',
          'format' => NULL,
          'safe_value' => '731 - SNAP General',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '555ee673-8f46-4dc6-a40b-ac4365807b55',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with LIHEAP (Low Income Heating and Energy Assistance Program)',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '5df7c995-7385-46fc-850e-df23bb401167',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '783 - INC Fuel Assistance',
          'format' => NULL,
          'safe_value' => '783 - INC Fuel Assistance',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '31a6da4f-a038-412b-af35-a6c39f4e908e',
    ),
  );
  $terms[] = array(
    'name' => 'I am being treated as an independent contractor, but I think that I should be an employee.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '5e8665e4-e13a-492c-abb0-1a02f0a47126',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '299 - EMP Other Employment',
          'format' => NULL,
          'safe_value' => '299 - EMP Other Employment',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '86a0f533-382a-4e9f-bdd3-03a5ee408067',
    ),
  );
  $terms[] = array(
    'name' => 'My issue concerns applying for MaineCare.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '5f29257b-bd0c-4357-91e5-e5168d49b9ec',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '508ef373-e252-4933-a31e-83198b205e2e',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4764391-fa37-4ea1-90d9-dab8e6b7ae32',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem with MaineCare.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '607483a3-27ad-49c8-9e64-1eaeb098351b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem with my town\'s GA program.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '60e8374c-03d4-4e7d-9f89-0600c910daaf',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
    ),
  );
  $terms[] = array(
    'name' => 'I missed work because I was a victim of violence, or because I needed to help someone in my family who was a victim of violence.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '61729110-dcc6-4b6c-8845-1109a49f05ed',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '299A - EMP Wrongful Discharge',
          'format' => NULL,
          'safe_value' => '299A - EMP Wrongful Discharge',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '27d8719c-f29d-4cd9-b784-cf600608e38d',
    ),
  );
  $terms[] = array(
    'name' => 'My problem is will my cell phone bill.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '62eab37a-e321-4af6-a177-f2efc16aa068',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem or question about Medicare.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-4',
    'uuid' => '6403c1de-3465-4cff-acc0-83709f0780a8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'The problem is with my heating bill; I heat with oil.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '6487618b-cb47-4f25-940d-6cf6b1ef0e86',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply but don\'t know if I qualify.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '649c6495-0135-45ad-89fe-1fa3083aa6d8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e74b20bd-de39-4cab-8883-7936192242ed',
    ),
  );
  $terms[] = array(
    'name' => 'I am a child or teen who is being abused or neglected by a parent or other family member.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '64cf603b-38ca-4392-956e-6ea5f3a13f6a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
        ),
      ),
    ),
    'parent' => array(
      0 => 'af936db2-1290-4648-97f9-5b53d0fc4f9a',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem getting help from another government program.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '650b7828-d774-43dc-ae5d-aad3fe174620',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '799 - INC Other Income Maintenance',
          'format' => NULL,
          'safe_value' => '799 - INC Other Income Maintenance',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8ea3018d-2d60-49ab-943c-49d53d2fae0d',
    ),
  );
  $terms[] = array(
    'name' => 'I  am being dunned for a payday loan I can\'t afford to pay.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '652c4eda-e84f-4029-92dd-9726fea5ff6b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '201ece9f-b22c-4e8e-ab07-c03e7c1dc53e',
    ),
  );
  $terms[] = array(
    'name' => 'I am having problems with my student loan debt.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '65453cf6-3d85-4de8-9693-3b368a4a0d03',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b5d4068f-bd35-4bd1-bca9-4592203ea2dc',
    ),
  );
  $terms[] = array(
    'name' => 'I have copies of the work policies and records of amount owed.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '65af084f-8fdd-4752-8f41-1c810fd07588',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b77a2787-42f9-41b0-b32e-b2915d4bbb8b',
    ),
  );
  $terms[] = array(
    'name' => 'I have a disability.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '66772567-a963-4825-8c2b-f22eba0fabc6',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'I was not in a union and I was not a permanent employee of the local or state government.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '66b0e165-af42-404e-a74a-aea285e61456',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ccaaba92-32c5-437d-958e-3c6b04895208',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a different problem with DHHS support collections.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '67be8854-4560-4f35-9405-dcfc7b53958e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9f102d50-cb84-41ed-888e-ecd08e327177',
    ),
  );
  $terms[] = array(
    'name' => 'I want to know how much I may get for the Earned Income Tax Credit.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '67eaeb1b-b8a9-4d9b-be3a-6322fb5a2b15',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4be96cfc-06c1-4050-bbb9-ba7942aa4b7d',
    ),
  );
  $terms[] = array(
    'name' => 'I believe that I am being harrassed because I reported unsafe or illegal behavior (such as a safety violation).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '681eea6c-9b98-4b44-8898-c177b3f23f48',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '259 - EMP Other Employee Rights',
          'format' => NULL,
          'safe_value' => '259 - EMP Other Employee Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3bda5ac9-46c2-4ecd-a417-2a450b61cc2f',
    ),
  );
  $terms[] = array(
    'name' => 'Native American Issues',
    'description' => 'racial discrimination, cross-border issues, tribal sovereignty, Indian Child Welfare Act, Jay Treaty, etc. ',
    'format' => '2',
    'weight' => '-10',
    'uuid' => '69191465-1d27-4267-8897-75a9f548203c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'world-icon.png',
          'uri' => 'public://world-icon_0.png',
          'filemime' => 'image/png',
          'filesize' => '2238',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '713cc4af-64dd-4cdd-8038-97c3ce39d746',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6RkQzRDdGMkY0QzhBMTFFM0E2QzRGMUY2RjgzOEE1QjIiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6RkQzRDdGMzA0QzhBMTFFM0E2QzRGMUY2RjgzOEE1QjIiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpGRDNEN0YyRDRDOEExMUUzQTZDNEYxRjZGODM4QTVCMiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpGRDNEN0YyRTRDOEExMUUzQTZDNEYxRjZGODM4QTVCMiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Pjzzw6UAAAUySURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoqEMHF2ChlkHKMmImWvJK0qIiArzF/SvL4j1YmJkfPn977sbD6/efD7xDhfi5tRSlbj96uaojg4OdFSIIdKilnoqanDiQ/f///5ia2X/+/fv4+fvjl+8GIOp5ONnL4z13Ty3+z/A/OcAW7ko0wMjImBXq9Ortp/W92bWpvvw8nHR1qK6KzJrurDgfqyev3l+6/STQ0QiPYit9ZV5uzr2nrke4mW3syzXTUaSTQ4OdjJe0pMiKCwHZy3accDHT4uJgw6MeGKiBjoZr950FskUFeefUJOD3GHUcGuZq2pjhD8woQPa///+B4eRuqU1Ql7ulztlrD99//gZkMzMzNWcGhLiY0NChFrpKNSk+wBCCcK/cefrl208LXWWCGqVEBeQlhQ+fvwUP47pUX2NNeZo4FJgPOvNCmZkQWs5ef6CrKsPKwkyMdqCzzl5/COcCzenOD+Pl4qB+8QQMOaDLkEX2nr7Oz8O18/gVTMXHLt65//Q1muCJy3fRFAMzFjDxEGM7I5GdO052NmEBbjTBZ68+CAvwsLOh+/bJy/fiwnxoIf3377/nbz4C0wATEyOy+JsPX378/E21EM2LcAYWRsgiP3//MYluml4Zq6koiaZYO7R2RlUcpMCHA6BrTGKbZ1bHAWsvZPG5Gw73Ld1FnTTKxMjobauHJvj8zQdgrgeGEJFeBdYIIgI8T1+9RxP3tTeA505KHaqlLCXMz4Mm+OLNJ6DdJNU0YkJ8L99+QhcU5NVQkKCOQ/VUZDAFP339LsjLRVLpBvTVhy/fsJivKkMdh6KlKphDf3BxsJPmUG7Or99/YYqryIpTLTMBMzKayJv3n4F1DKY4BLx8+5GLHb1e/fHr96t3n3BpoU7xNDQazjUpvrYGqmiCWw5f3HH8ypSyaCw1e07fjKpYRSn0BNOxYJsgH1d6kAOa+P6zNzrmb6NO1MuIC6KJAIv0P3//YYrDZPkxpTjYWIEZH1P8/7//1MlMdx69xBQEVtPfvv8kKfo+fvmGtUF498kr6jj04u3HWLIwL9fHL99JdOh3AWwl2sXbT6jj0BsPXrx4+xFNUEKYD5iL3336SrxDX7z9JCmCXpM9ff3hNrYYI8ehwA7ahgPn0QQlRfiBxdPz1x+IdOW3H7/efvwijVHlbth/jprFE6Smxmw9AXuhmN06PK0noEMZ0VpP778AY4ZqBT6w7aOhIOllrYssuGTbCWDmCHJC7wAV9a2M87YCBjmy4JELt09duV8U44YsuPXIpScvr1OtHIWAk1fuVSf7ANsQSNXPJ2BDGNgfwlC70kpfBa2Zd/DcLVNtRWTFQO110zdQvyvy+euPsomr//77h9y7uHrvGTHNXki/Bbmj/PvP39KJq74QXcCR1rk7ffU+MAyAeQvC1VSSAjagTl69R1AjsFsCTKB2hmrw3Fk/YwNyF4r63WVg9q+fsRGYMyANahdzrZ3HrxLUBVRjqqUAKUSBeoEmbDx4geYDEGv3nU1uXvDq/WcgO8jJePeJq/hjENgR2HjwfLCzCaSHlNa6EDIYQY8hHWAa8CuctHznKRVZMXUFiXV78Vl84MwNYAfLyURj1e7TQF0nLt8jw0byR/OAeatlzub5Gw+rK0jO2XA42NmYm5Mda2Uxfc0BSWH+wJIpj16QP5pH6bAjsAJ8Cq6cIqtmAVOhkowopF44fO4WsDh7+vL9uZuPrt17Rnl7lHF00nbUoaMOHXXoqENHHTrqUHIAQIABADFaB7UK2ikiAAAAAElFTkSuQmCC',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'b955c0ef-818a-4c79-8b3e-e5a3ad16cb87',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'My employer is using drug testing; I don’t think this is legal.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '69f0c991-e9ee-4d90-a289-d0b247f7e91b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '259 - EMP Other Employee Rights',
          'format' => NULL,
          'safe_value' => '259 - EMP Other Employee Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'My legal issue relates to a former job where I was fired, laid off, or quit.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'A health care provider has billed me for a service that MaineCare should have covered.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '6c7fe477-93f5-4878-bd60-eb775a090ccf',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    ),
  );
  $terms[] = array(
    'name' => 'None of the above apply to me.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '3',
    'uuid' => '6cbbe9fe-2481-4742-a004-b86f36a28c6a',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'I need help with my credit report.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '6d05a801-ca46-4417-bf55-27c9b8dc3f03',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with getting rental assistance.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '6d39bcdb-2d69-4188-8cfc-11024794536a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7501a644-65bd-4e23-82af-86857bba181c',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem getting my license or other government documents issued to me.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '6d677929-ad97-46f6-8dc8-d1ec1d711220',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '939 - MISC License - Other',
          'format' => NULL,
          'safe_value' => '939 - MISC License - Other',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    ),
  );
  $terms[] = array(
    'name' => 'The conviction information is false.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '6df29de3-01f5-4dbe-9db4-27c29ba1f409',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'df7011b5-6ba7-45cd-9b5d-66b5b553c409',
    ),
  );
  $terms[] = array(
    'name' => 'I am having problems with a bill.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '6ef398cc-6677-4093-bd8e-c74f39f6175a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd0593461-e989-4aa2-a2d0-cb41210b6450',
    ),
  );
  $terms[] = array(
    'name' => 'I think that I was fired for other reasons or for no reason.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '6f55c5d0-f2dc-46a2-98ce-d1671474bae7',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '66b0e165-af42-404e-a74a-aea285e61456',
    ),
  );
  $terms[] = array(
    'name' => 'I have not contacted the seller.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '6fe906d5-c3a1-44d6-90c4-e61641b1f22c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '42185365-84f3-40ef-b55f-fefa3674be4d',
    ),
  );
  $terms[] = array(
    'name' => 'I need a safe place to live.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '7127cb2c-189b-485c-91e9-7e5d63301689',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with the Earned Income Tax Credit.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '714be29e-8a5f-45a0-936b-019bb9bdcc9d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '231 - TAX EITC Federal/Federal & State',
          'format' => NULL,
          'safe_value' => '231 - TAX EITC Federal/Federal &amp; State',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4be96cfc-06c1-4050-bbb9-ba7942aa4b7d',
    ),
  );
  $terms[] = array(
    'name' => 'I don’t know where my case will be tried.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '72bd4767-e110-4280-a1f9-7b0b1c3e638c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b401fe9d-9865-48b2-8326-5962c259d514',
    ),
  );
  $terms[] = array(
    'name' => 'I am living in a motel long term and want my lodging tax payments refunded.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '7301bd94-63d9-48c7-aecb-f158f399074a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '695 - HOU Inn/Hotel/Motel Dispute',
          'format' => NULL,
          'safe_value' => '695 - HOU Inn/Hotel/Motel Dispute',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e0292fc9-7c7d-476b-b893-6f7f5b5b49be',
    ),
  );
  $terms[] = array(
    'name' => 'Low Income Eligibility',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '738edc81-a983-49d8-baa0-bf32e322e744',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'triage_income_eligibility',
    'field_pov_range' => array(
      'und' => array(
        0 => array(
          'value' => '0,200,2000',
          'format' => NULL,
          'safe_value' => '0,200,2000',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'My ex filed a request to change the DHHS child support order.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '73e153be-12a7-44de-8c9b-efc2855b4f97',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'eb6da79f-0133-4f15-8053-f1f9cbf7b134',
    ),
  );
  $terms[] = array(
    'name' => 'I am interested in becoming emancipated.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '742f312f-26fd-41a4-ac4d-fb2f8f00a1de',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '431 - JUV Emancipation',
          'format' => NULL,
          'safe_value' => '431 - JUV Emancipation',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'The person harassing me is a family member, a member of my household, or a former partner.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '74fb485a-6ed4-4dd7-9ad7-0c14551c3a1b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b0dcffab-3413-4ff6-b09b-5cea8f38a7a8',
    ),
  );
  $terms[] = array(
    'name' => 'Housing',
    'description' => 'renting, security deposits, home foreclosure, homelessness, other rent & homeowner issues',
    'format' => '6',
    'weight' => '-3',
    'uuid' => '7501a644-65bd-4e23-82af-86857bba181c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '0',
          'filename' => 'home-icon.png',
          'uri' => 'public://home-icon_0.png',
          'filemime' => 'image/png',
          'filesize' => '1631',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '6007359e-22c5-4f91-b8f5-df76382db1e6',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6QkM5MzMxQzI0QzhBMTFFM0E5MzlENzI4Mjc2Q0UxNzAiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6QkM5MzMxQzM0QzhBMTFFM0E5MzlENzI4Mjc2Q0UxNzAiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpCQzkzMzFDMDRDOEExMUUzQTkzOUQ3MjgyNzZDRTE3MCIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpCQzkzMzFDMTRDOEExMUUzQTkzOUQ3MjgyNzZDRTE3MCIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Pg2bmLUAAALTSURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoCHEoCx3sKIl1dzXXhnPvPnlVMmHVtx+/BtKhIgI8zmaa7Kysh8/fuv/sDUTQ2kBVRlwQrgbIVpMTv3Dr8YA51N/BsC7Vl4ONFRKKk1funb3+EPYEx8Q0YGk00t2sNSsQ4kogYGZmKohyzQl3ArJX7z79////QZFGozzMq5K8GRkZ0cQzQxz//fs/bfV+YIpsygxgZmIaSIfGelmWJ3hiuhICssOc/vz9N2vdwS/ffvYUhrGyMA9M8RTvY12R6IXLlRCQH+mS6Gez59S1zPbF33/+GgCHJvnZlMV7EFlCxXlbHb90N6V54aev38mwi1lQzYo8V6YE2BXFuBGv3lpf5cPnb7tPXjty4fb3H7/ff/pKjzSaFmQPjFCStACTBzDD/f33b+Wu03QKUWBezotwJsMyoFvtjNRevv10/f5zmjs0I9ghlyxXwt1qb6L+/PWHGw9e0NChwJKoONadwoIC6FYHE/XHL9/fevSSJrnezUIbWF5SpYIAlvxtOUFWesrUd6i4EB+wasFfXpLq1vo0f2BNS2WHpgba8XJxULepBWxG2RioUtmhTqaatGiqAtt7VHYosKymuivffvxy6PwtKuf6k1fuS4rwK0qLUsuVwGa1V96EV+8+UzlEHzx/0zZvKxWD8/efv0A02gsddehovx4DzFh7YPXuM8i9dWCvA9iu87DSGVwOBTaHX7z9iCZ4/NIdajmUalHPyIClGfD95+/RzDTqUPo59Nfvv1S0+N+/f7Ry6LtPX4HtHZJM/4p7bPHe0ze0cuj////nbjhCkun///3H1SJZuOUoDdPooq3HZq47+OcvRWng/edvhb0rrtx5SlrxR8akrRA/t56qLDsrSmVx6sq99xiNa1FBXiMNeWSRT1+/n7/56Afp5Svj6OzyqENHHTrq0FGHjjp0UAGAAAMAJ8T8rOefW60AAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'I have another problem with DHHS child support collections.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '75f94a9d-76ef-4955-804e-362ef572c8fc',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'eb6da79f-0133-4f15-8053-f1f9cbf7b134',
    ),
  );
  $terms[] = array(
    'name' => 'I am being evicted from the mobile home park.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '7696b260-405f-4e1e-929e-b11ec07e7f0a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '651 - MOBILE Eviction - Home Rental',
          'format' => NULL,
          'safe_value' => '651 - MOBILE Eviction - Home Rental',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '78f5751f-e6ea-4460-984c-cb743da5c743',
    ),
  );
  $terms[] = array(
    'name' => 'I have other issues that relate to the abuse.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '76b309a6-14c7-4821-8d1c-08fb07f6131b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    ),
  );
  $terms[] = array(
    'name' => 'I have transportation issues to and from school.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '77435812-cda5-4edd-9cbc-a50c91466940',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '142 - EDU Homeless Student',
          'format' => NULL,
          'safe_value' => '142 - EDU Homeless Student',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'I have not filed a due process appeal yet.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '778baebb-93aa-4fcc-b4d1-3e6abfb21389',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '43cf7f30-fa26-4b8a-86d1-b30a2b5c94a9',
    ),
  );
  $terms[] = array(
    'name' => 'I am the victim of identity theft.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '77d8a7c9-5b3b-4749-9958-acb618942b73',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '10203af7-8605-4fb6-ba14-617fdae48265',
    ),
  );
  $terms[] = array(
    'name' => 'I can\'t afford market rents and want to apply for rental assistance.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '78ef363a-f01b-42dc-9a21-1e3432be0882',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6d39bcdb-2d69-4188-8cfc-11024794536a',
    ),
  );
  $terms[] = array(
    'name' => 'My mobile home is in a mobile home park and my problem is with the park owner.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '78f5751f-e6ea-4460-984c-cb743da5c743',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8d0d7bc5-f165-445c-a81e-ea6a0336db31',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with my neighbor.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '791903df-1f73-4935-8e77-51fbcd85e2be',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f038138e-92ac-4103-a846-4a8dd46b6547',
    ),
  );
  $terms[] = array(
    'name' => 'I have used up all of the appeal steps and did not get my job back.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '79faa5a2-7156-487c-9da2-92806dfb5d6e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '299A - EMP Wrongful Discharge',
          'format' => NULL,
          'safe_value' => '299A - EMP Wrongful Discharge',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '43cf7f30-fa26-4b8a-86d1-b30a2b5c94a9',
    ),
  );
  $terms[] = array(
    'name' => 'I want to keep my home.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '7a6680be-c3be-4c6b-9f41-53faee23d927',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '671 - HOU Home Mortgage Foreclosure',
          'format' => NULL,
          'safe_value' => '671 - HOU Home Mortgage Foreclosure',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '13ccb7d2-ece5-4b19-a02a-129a9292dee6',
    ),
  );
  $terms[] = array(
    'name' => 'I have applied for TANF but haven\'t gotten an answer from DHHS.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '7a90d6bc-790b-416d-983d-95804491b5b0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '712 - TANF Eligibility',
          'format' => NULL,
          'safe_value' => '712 - TANF Eligibility',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9d2eba9c-cc98-4569-b093-f8a1172e9ba4',
    ),
  );
  $terms[] = array(
    'name' => 'I have a question or issue with my retirement benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '7be8ccf2-2f2f-43de-89d2-d723b767d65f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'I need help figuring out what do to make myself safe.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => '7ce2624e-3093-4beb-8435-e699d888b4bd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    ),
  );
  $terms[] = array(
    'name' => 'I am 60 years or older.',
    'description' => '',
    'format' => '2',
    'weight' => '-5',
    'uuid' => '7d2e841a-3c1a-401b-92f2-652f87c0178f',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'I want to get my personnel file.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '7d5d6682-9821-4d3a-a7af-6749f1ebaa88',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I am having problems with a "repair-your-credit" auto loan.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '7d990886-e009-4354-8593-17856f05de75',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '201ece9f-b22c-4e8e-ab07-c03e7c1dc53e',
    ),
  );
  $terms[] = array(
    'name' => 'I am being sued.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-4',
    'uuid' => '7ecc2a72-2e36-4c75-bf55-f29e817db229',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'My former employer will not give me a truthful reference.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '80039820-9209-4d59-9d50-b30b516d8e35',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I got LIHEAP benefits but I need more fuel assistance.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '80b1f52f-deb6-411c-9839-c13a76786722',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '20d8f25e-49de-42f3-aca2-75333b3745b0',
    ),
  );
  $terms[] = array(
    'name' => 'I want to file for separation.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '80b2cbdc-99b3-4c84-8282-bd0c4663b68b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '39d64169-94d4-46cf-ae79-87220c874bbf',
    ),
  );
  $terms[] = array(
    'name' => 'I have a disability and I need time off to get treatment that will enable me to return to my regular job.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '81010481-bfec-4723-a8e5-2f65e8b42ee2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4e783cd4-06d6-47cf-9324-5da03a344294',
    ),
  );
  $terms[] = array(
    'name' => 'I am being evicted from the land where my mobile home is located.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '8137bb80-a665-46df-9e57-d5f48e97b8b9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '652 - MOBILE Eviction - Lot Rental',
          'format' => NULL,
          'safe_value' => '652 - MOBILE Eviction - Lot Rental',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5290eb9a-1b0b-4e91-b0ad-77644b11bf29',
    ),
  );
  $terms[] = array(
    'name' => 'My status with DHHS is preventing me from finding work or getting a professional license.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '816fb444-6eaa-4e5c-bc46-4bc1c4909455',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '353 - DHHS Abuse/Neglect Substantiation',
          'format' => NULL,
          'safe_value' => '353 - DHHS Abuse/Neglect Substantiation',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '53467ab1-c9d5-4c87-8016-e79c61a95c63',
    ),
  );
  $terms[] = array(
    'name' => 'I am 60 or over, and I need help with legal issues that arise with aging.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '818766eb-903a-4a3b-8031-be228d441534',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '593149a7-b796-4947-a9ab-7e8ae6d2c237',
    ),
  );
  $terms[] = array(
    'name' => 'I have lost a professional or occupational license.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '8272716f-3c75-4c8f-87d7-5b10a2430cd6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'acba75bd-7ecf-4a3a-90b0-0872149ef740',
    ),
  );
  $terms[] = array(
    'name' => 'My child has another school-related problem that I don\'t see on this list.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '837a874b-acc2-4bd2-9061-14c9efe36fe1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '199 - EDU Other Education',
          'format' => NULL,
          'safe_value' => '199 - EDU Other Education',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'I have another type of problem with my rental housing.',
    'description' => '',
    'format' => '2',
    'weight' => '3',
    'uuid' => '8430971f-2a08-4e12-a862-7ef28568a070',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I have been arrested or charged with a crime.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '84672b11-8bad-4950-afbf-fc54c4e545b1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2391ff3e-3792-4a5f-a8b6-15722faf504e',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with funeral or burial plans.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '84cf3395-37a7-4680-b718-2e85e20bf564',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'I have applied and they denied me.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '854a06f4-59e4-4998-ae61-1f153edf6f86',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e64887db-bf03-4362-9ee9-0f5ff447d301',
    ),
  );
  $terms[] = array(
    'name' => 'My criminal record is accurate but it is preventing me from getting a job, a professional license, or pursuing other rights that most people have.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '85b53bcf-96ec-4d7f-b4ac-173a80d53c83',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c63dd1ca-abc4-46b8-929f-3b4fe3b09a81',
    ),
  );
  $terms[] = array(
    'name' => 'I have another legal problem or question that mostly affects older people.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '3',
    'uuid' => '861f3132-aa49-4d6b-9adf-f79455197d99',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'I have different job-related issue that I need to talk to a lawyer about.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '86a0f533-382a-4e9f-bdd3-03a5ee408067',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'I am an adult or have been charged as an adult. I have been charged with a criminal offense or "civil offense" (includes traffic offenses).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '86b18f1b-0a3e-4b39-8baa-cf469aba4676',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    ),
  );
  $terms[] = array(
    'name' => 'Health',
    'description' => 'MaineCare, Medicare, Obama Care, health insurance, medical bills, medical malpractice',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '8733c819-ac49-4a50-8655-8606946aea67',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'health-icon.png',
          'uri' => 'public://health-icon.png',
          'filemime' => 'image/png',
          'filesize' => '2264',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => 'd5ad14c2-14b8-4dee-bafa-16d86d4ff9a9',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6RkZBODc2RjA0Qzg1MTFFM0ExNzJEOTdEMjQxREJFN0IiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6RkZBODc2RjE0Qzg1MTFFM0ExNzJEOTdEMjQxREJFN0IiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpGRkE4NzZFRTRDODUxMUUzQTE3MkQ5N0QyNDFEQkU3QiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpGRkE4NzZFRjRDODUxMUUzQTE3MkQ5N0QyNDFEQkU3QiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PhHAxdoAAAVMSURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoqEMHF2AhVYOsuJC5rpKStAgXB/vX7z9vP3p59OKd1+8/49EiIyZoqaesJC3KycH25duP+0/fHL9899nrD7RyqK6KTGG0q7mOEpr437//thy51Lt459uPX9Ck5CSEKhK97AzVGBkZkcX//f9/6OzN3iW77j19TaTtzIJqVsSoi/O26i0Mk5UQwpJ6mBg1FCSCnIwv3XmCHE5e1rqzahOUZcTQXAkEQBEFKZFgZ+MXbz/dfPCCag5NDrAtjfMAOgiPGg42Vm8bvfM3Hz199R7I9bHV78wLYWFmxhebzExOphqPXry79eglFTKTgbpcfqQLMZ5mZWGeWBopIy6oJifekhWIGZCYAKimMd1fUUqE0hAFGjSlLFpMiI/IlMTOygKMawcTDWCeIzaXsDBLiwtuPXKJoswEzK2aipIkZU8rPWVSSxJ7I3UVWbE7j1+RH/U+Nnr0KSaBaZqiNGqhq0wfh2KWeiQ4lIeTXVyYjz4OVZYRJd+hQvzcdKshuTnZgRmRTIcCi0Z61ubseK3D54k3H75QyxEfPn/bcfzKobO3nrx6D6xpBfm4gWWtg4m6u6UOJCB//PoNbDmQ6dB3n77ef/paUVqUEif+//9/4ZZjM9YeYGJkdDLVtNBV4mBnBbr1xoMXjTM3TVmxtzLJ29FE49KtJ3///SO/HN15/GpGiAPZrvzx83f5pDVHLtzODHWI8bJES0vvP38DOjS3a1lOuNPrd58J1GH4h3SE+Xl2TS0ChgF5DgW68tjFO9MrY3VUpHGp2XPyWsmEVf/+/ccfogSq0O8/f3FzshlpyJPhyo0Hzs9ef3h6VayBuiweZUoyoiKCvPtOX6e0UTJ99YGHz9+S6kpgI3Xyyr2hribGmiiebJ69uahv5ZwNh5AFg52MDNRkKXUoMD9WTF7z+89fkhx68ur9528+JvnZoIkfPHdz5/Er564/Qmv6JPrbUKHPdOn2k5a5W0hy6NnrD9QVJKREBSDcn7//fPr6HYiAbXsg9/ffvxDun79Q/1vrqwBbiVToiqzZc0ZeUhgzhHCBF28+ykkIw7mLtx7rX7obzgXmMMuENiBjWmUMsOkEZHCys4kJ8j7F3ZEioRfat2TXxoMXiFT8+dsPLg42kiKBg52NOp07YNFdO209MxMjwSYZEADrHkifBAL0VWWB/RkgY+XOU1++/wQ2q90stUG9P6T29ZsPn6nWXQYWdVVT1n3/+TvUxQS/Si1FqZ3HrgCzICTlmWorAhGQse3IJaBDgV3nomg3ZPV3n7z6+OU7NQcggG5tmLlxysp9/8HZAhcA1uPffv7af+YGkcZuOniROt1lNHDm2oMHz94AO+wsOLIqsC0LLH03H7oY7GIC7G0iWuJ6ysBesrOZJj8PJ1wQWJBVTFnz5+8/6jsUCG4/fgWsxO2M1Hi4OLAPWKjKLNh89N6T1y5mmvAeKbBOBuZuZFcC2wPprQuBbqVJiELA6/eftxy+qKssLS0miDVQgVX8pOV7rj94bqOvys6GJT8Ay6Os9iVX7j6l2kgJ7sbAb2D8AotxYFXJhNGRlxThf/Ds7Y5jV9buPfvr919BPi5BXi5g6AIr2Mt3nszbeKR66jqCYUlU64l4YKKl0JkXIiHMDxcBtpGBde/5G49QR0eYga2cT19/4M+L1A9ROHj2+sP6fecE+bk1FSSBYbbhwPnczqWPXrxDUwYM+5+//pBhPiPVpxhtDFSBDj18/tYAj48SBMCigBZdv9Gh8VGHjjp01KGjDh116KhDyQIAAQYAu6v84iuYUT8AAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'I applied for Food Stamps but was denied.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '876fc8e3-c03c-42d5-94a8-23a7e5a48848',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '731 - SNAP General',
          'format' => NULL,
          'safe_value' => '731 - SNAP General',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '558cd122-db93-4f43-adc9-be37f59ff004',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for MaineCare for myself or my children. Do we qualify?',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '8785b2c5-be32-45a6-9b9b-5aec1e6431cd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '508ef373-e252-4933-a31e-83198b205e2e',
    ),
  );
  $terms[] = array(
    'name' => 'I have a school-related problem.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'The person to be protected is an elderly or disabled adult.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '89676521-216f-46c4-abfc-307898df2b74',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e46e5a74-85bb-4b73-8ea7-feb61d39955b',
    ),
  );
  $terms[] = array(
    'name' => 'I have another legal issue with buying a home or getting a loan.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '8b6aaa5f-025c-4ab8-bb87-e10391134dc1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ef6ffce8-ae1e-4df0-9e72-92c9ca1a34b7',
    ),
  );
  $terms[] = array(
    'name' => 'I have another military-related legal problem (such as AWOL, missing drill or discharge status issue).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '8ba127dd-f76c-4da6-8ae9-6454bdf42d92',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'af4345ac-4bac-4986-97f2-e286f653b28d',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for LIHEAP fuel assistance.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '8cade8c5-c315-4726-a575-cde90ae28228',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '20d8f25e-49de-42f3-aca2-75333b3745b0',
    ),
  );
  $terms[] = array(
    'name' => 'I live in a mobile home that I own.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '8d0d7bc5-f165-445c-a81e-ea6a0336db31',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7501a644-65bd-4e23-82af-86857bba181c',
    ),
  );
  $terms[] = array(
    'name' => 'I am an agricultural worker.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '8d52f8eb-4abb-4ac0-8e43-c6f0a3d0b35a',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'I want to get my marriage annulled.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '8d7ec944-4076-494b-891c-61027e59c039',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '39d64169-94d4-46cf-ae79-87220c874bbf',
    ),
  );
  $terms[] = array(
    'name' => 'The person to be protected is a minor.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '8dc89d9d-e5da-443a-a3ab-d5049b8e6280',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e46e5a74-85bb-4b73-8ea7-feb61d39955b',
    ),
  );
  $terms[] = array(
    'name' => 'We have a boundary dispute.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '8df8f461-40c7-4f0e-987b-ff3b8f592f7c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '97eca8ab-4131-43e2-90bc-2e1064075c2c',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with other kinds of benefits.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => '8ea3018d-2d60-49ab-943c-49d53d2fae0d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'de934714-cdfb-4476-9a1e-5c3d1c3d6896',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'Immigration Issues',
    'description' => '<p>green cards, asylum, becoming a citizen, other immigrant status issues</p>
',
    'format' => '2',
    'weight' => '-8',
    'uuid' => '8ec455e1-1737-4ed7-a97a-6896c8fe43e6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'immigration_0.gif',
          'uri' => 'public://immigration_0.gif',
          'filemime' => 'image/gif',
          'filesize' => '480',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => 'b537fd85-a67d-4b7a-aeab-fb2bdce2cd03',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '50',
          'uuid_features_file_data' => 'R0lGODlhOAAyANUAACJMcp2dnfr6+tfX18/Pz+Pn6szMzLi4uG1tbenp6d/f3/Pz87jF0q2trdHR0dnZ2eHj5dPT0+Pn7PX19dvb2+3t7f///+Pl5/f399XV1ebn5+Po7eHh4eTk5N3d3evr6+/v7/n5+eXp7ePj4+Pn7ePl6efn5wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAAHAP8ALAAAAAA4ADIAAAb9QIBwSCwaj8ikcslsOp/QqHRKrVqvVwiige0SBxaCd+wIl8Zdi2UxQGPBYvc1EpbPLQq7tWOptAEBelEaagQHBQQlBoJOJQoWDmVqDnmMSxsEFgOZahYREpZKEpkJnJAEF6FJJZ0EGGp/qkgcnbVxskestWoRuEl8u3W+RhfBsMNFDMYWFACbyEIfxhOEmtAUy7UJyKbZFhigsgXewbGWtOS1HLjo6beqBunCssrp5qr1xhQLfdDdtgAohBv2yJgAaEMkGRuITGEwBggBOKw1ISIAOsbecVu2yN+/XQQ8IJOnURU/ciVDgXA3kuUwksgYyJxJc6bFmzhz6kQSBAA7',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '52f72c5f-b8bb-4ee1-80ef-42986fc1ea34',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'I need time off because of a minor illness or for other reasons.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => '90085075-d855-49bf-ab02-d8ed09df890e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4e783cd4-06d6-47cf-9324-5da03a344294',
    ),
  );
  $terms[] = array(
    'name' => 'I have contacted the seller and can\'t come to an agreement.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9036b4d1-6cc9-4d0b-96ad-f342900080d4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a024519-29d7-4c3c-867a-da32cd3aa63a',
    ),
  );
  $terms[] = array(
    'name' => 'I have run away from home and am homeless or need to find a place to stay.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => '90b40e31-5051-4a73-b1e8-20f73e0e394a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '432 - JUV Runaway',
          'format' => NULL,
          'safe_value' => '432 - JUV Runaway',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd4cf083f-648e-467f-87d0-f509c3104c45',
    ),
  );
  $terms[] = array(
    'name' => 'I do not have children in my home.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9200b073-8566-42a5-9f11-9289e51fabcd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'dace9efc-5677-4311-b6d7-66f11d8c704d',
    ),
  );
  $terms[] = array(
    'name' => 'I was abused by the police because of my race, my sexual orientation, or some other discriminatory reason.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '92d0bd8a-5028-4201-a520-1a8fe3a7b278',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2391ff3e-3792-4a5f-a8b6-15722faf504e',
    ),
  );
  $terms[] = array(
    'name' => 'My employer wants to settle my claim, and has given me a settlement agreement.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '930f1c1a-ba90-4ecc-ae30-f499b576ddd4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '44773640-bbcf-4d01-95b6-2397f47e8bc3',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with paying my property taxes.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9349aebc-f621-4eb7-92a1-d8e3a263185f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b7770d7c-ed49-4df6-8df6-9bf4a88c3aa5',
    ),
  );
  $terms[] = array(
    'name' => 'The bank has not contacted me yet, but I am behind in my payments or about to fall behind.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '939bcf59-beee-4012-af9b-d1be38699ad5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '970d6f59-bbc4-4a96-966e-fa74c6d45ffd',
    ),
  );
  $terms[] = array(
    'name' => 'I have been charged with a juvenile offense.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '943ca403-8304-489c-8f12-997674c998eb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
        ),
      ),
    ),
    'parent' => array(
      0 => 'f39a9ae3-9929-4362-95d8-3e770f66eecc',
    ),
  );
  $terms[] = array(
    'name' => 'The policy does not say anything about paying accrued PTO, sick time or vacation pay at the end of employment. Or I cannot figure out what the policy says.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9467468f-c92a-4646-bd4c-36ff8904f91a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '65af084f-8fdd-4752-8f41-1c810fd07588',
    ),
  );
  $terms[] = array(
    'name' => 'I want to know how to buy a house.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '9544f2c9-6bee-44d0-af2f-b8a61230166c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ef6ffce8-ae1e-4df0-9e72-92c9ca1a34b7',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem or question about coverage under the Affordable Care Act (ACA or Obama Care).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => '95b84d6e-6df0-485f-b6ba-7fc6823ffa69',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'My complaint is against another licensed professional.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '95e9dd16-2af0-4001-98c0-682947df4392',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e02015ef-b772-42f5-9e2c-a7f959a07c10',
    ),
  );
  $terms[] = array(
    'name' => 'I have not yet given written notice to my employer.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '96cbda6e-6564-4aeb-9c56-d8c09757335c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c41c270b-14ba-4897-837f-4ceb4cf831e2',
    ),
  );
  $terms[] = array(
    'name' => 'I am still living in my home but afraid of losing it.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '970d6f59-bbc4-4a96-966e-fa74c6d45ffd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'cd2f0b1b-ed39-4248-b5a4-23ddacf6099d',
    ),
  );
  $terms[] = array(
    'name' => 'I want a tax abatement based on a reason other than inability to pay.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '978d5799-e23f-4a87-bcf8-527f65a3d246',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9349aebc-f621-4eb7-92a1-d8e3a263185f',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with my neighbors.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '97eca8ab-4131-43e2-90bc-2e1064075c2c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '00b8afef-bf42-4520-a1a7-e28f384bfa8c',
    ),
  );
  $terms[] = array(
    'name' => 'My town or city helps me pay my rent.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => '981fef48-e374-4ce1-b7f4-f4bc03ee6223',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '24fb4aa7-08e1-467c-9668-bc32d9312ad5',
    ),
  );
  $terms[] = array(
    'name' => 'The problem is with another utility.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => '98520370-d843-4ee0-9c71-8f2c1976213d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a similar problem with my federal taxes for a different tax year.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9ae91ae1-ea75-41fa-9f18-f8a6013fcf49',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '06f4a7d3-c02e-43bb-b9ed-89c9c1442c2a',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS is cutting me off from MaineCare.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '9af80907-ef75-4492-a9ad-94dc2ae917cd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '513 - HEA MaineCare Adult Elig - Non-Med',
          'format' => NULL,
          'safe_value' => '513 - HEA MaineCare Adult Elig - Non-Med',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    ),
  );
  $terms[] = array(
    'name' => 'I am not a citizen of the U.S. Can I qualify?',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '9afab62a-a9e4-4ddd-8261-eecc4a5e4ade',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '508ef373-e252-4933-a31e-83198b205e2e',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has charged me with an overpayment.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '9b8ad9d5-36a9-47e5-8c6c-d1785f8f540d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '731 - SNAP General',
          'format' => NULL,
          'safe_value' => '731 - SNAP General',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '555ee673-8f46-4dc6-a40b-ac4365807b55',
    ),
  );
  $terms[] = array(
    'name' => 'I do have the documents showing the results of the background check.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9b9602db-f2d9-422e-9c69-90493b4a5f4f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6df29de3-01f5-4dbe-9db4-27c29ba1f409',
    ),
  );
  $terms[] = array(
    'name' => 'I am a child or teen with family issues (such as, abusive parents; teen parenting).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '9bb6960c-1a1d-4f6f-b95b-ece1b754acdd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
        ),
      ),
    ),
    'parent' => array(
      0 => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    ),
  );
  $terms[] = array(
    'name' => 'I have been sued for credit card debt.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '9bea0cf0-55a0-48ac-93fe-039e543fdafa',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '023 - CON Credit Card Collection',
          'format' => NULL,
          'safe_value' => '023 - CON Credit Card Collection',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'I am being involuntarily committed to a hospital or being forced to take medication and I want to fight this.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9c295410-4279-439c-933d-2f1c6c03f09f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5bad7faa-692f-4a4c-a42e-5d6f4ce3e988',
    ),
  );
  $terms[] = array(
    'name' => 'I have applied for LIHEAP but was denied.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => '9c3e9786-57e7-4d58-84e7-a7e4eefcf4a9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '783 - INC Fuel Assistance',
          'format' => NULL,
          'safe_value' => '783 - INC Fuel Assistance',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '20d8f25e-49de-42f3-aca2-75333b3745b0',
    ),
  );
  $terms[] = array(
    'name' => 'I lost my drivers\' license for some other reason (such as traffic violations).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9c78a26b-5a40-436a-b0ea-46178479ad89',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '228b0a63-da88-4fe1-9e79-9be6a6be7690',
    ),
  );
  $terms[] = array(
    'name' => 'I can\'t find my family law issue in this listing.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9c9dfd20-634e-4ba3-9b7f-51b7c8c3923f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'fd55042b-8fa2-49e9-b73f-d747e8771702',
    ),
  );
  $terms[] = array(
    'name' => 'I already have a case pending at the Maine Human Rights Commission or in court.  I need help from a lawyer.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9cff56b8-9da4-4506-8ae0-95ec904f9d88',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '44773640-bbcf-4d01-95b6-2397f47e8bc3',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for TANF or I\'m having a problem with my application for TANF',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => '9d2eba9c-cc98-4569-b093-f8a1172e9ba4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '119990b0-9a61-4daa-9465-86d3627e80ec',
    ),
  );
  $terms[] = array(
    'name' => 'I have not filed my taxes and need help with filing.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '9d49fc3d-72cc-44ac-b09b-e3912286dce2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad7cb45a-033e-467c-936a-09bcfad3e732',
    ),
  );
  $terms[] = array(
    'name' => 'My problem relates to buying things or services, or is debt related, but I don\'t see my problem here.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => '9e75de33-f689-4779-aa06-c2c650330f89',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS is coming after me for child support, or I pay child support  through DHHS.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9f102d50-cb84-41ed-888e-ecd08e327177',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f0ad725c-b9cc-46f3-ac41-dd66d9924f2d',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with VA disability benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => '9f3db203-8bc0-4825-952d-4224cc41f019',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2dec907d-f540-4f0c-b75d-f72d63278ef2',
    ),
  );
  $terms[] = array(
    'name' => 'I don’t think I\'m getting the coverage I was promised.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9f66c566-4363-457a-8740-5c0d70ab42ce',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd0593461-e989-4aa2-a2d0-cb41210b6450',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with the taxes on my home.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => '9f6f8172-aa80-4870-9585-cf590357f3b3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '9349aebc-f621-4eb7-92a1-d8e3a263185f',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'bad14cf3-9a7e-4e33-a94c-7685c0079e59',
    ),
  );
  $terms[] = array(
    'name' => 'I have received court papers setting an eviction hearing date and time.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => '9fc1a99b-d8d1-4409-9d28-8349c2d417c3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '631 - PRIV Eviction',
          'format' => NULL,
          'safe_value' => '631 - PRIV Eviction',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '14a537c1-8f1d-4631-81d2-9492cd2fc9a4',
    ),
  );
  $terms[] = array(
    'name' => 'My problem involves only my Maine taxes.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => '9fc87af5-d3ee-4b41-b551-e50a487eff40',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '06f4a7d3-c02e-43bb-b9ed-89c9c1442c2a',
    ),
  );
  $terms[] = array(
    'name' => 'I identify as Native American or American Indian, and I have a legal issue that relates to my status as an Indian.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '69191465-1d27-4267-8897-75a9f548203c',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with my payroll withholdings.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'a02d4923-484e-4e17-92bd-e761cc62789f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e0292fc9-7c7d-476b-b893-6f7f5b5b49be',
    ),
  );
  $terms[] = array(
    'name' => 'I believe that I am being harrassed because of my sex, pregnancy, sexual orientation, race, color, disability, religion, age, ancestry, or national origin.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'a05ea17f-a81d-448d-9ee3-b7dd5b242ff5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3bda5ac9-46c2-4ecd-a417-2a450b61cc2f',
    ),
  );
  $terms[] = array(
    'name' => 'Where can my family get no-cost or low-cost dental care?',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'a088136d-b419-4305-9735-d585ccf54464',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4120096d-a572-4152-9528-32b2a6d0187c',
    ),
  );
  $terms[] = array(
    'name' => 'My lender is threatening to repossess my mobile home.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'a17949b0-a1a2-4a65-9f99-fd9e452a150a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '656 - MOBILE Installment Contract',
          'format' => NULL,
          'safe_value' => '656 - MOBILE Installment Contract',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8d0d7bc5-f165-445c-a81e-ea6a0336db31',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem or question about ASPIRE or PaS.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'a2203d64-a966-4d4f-af1e-5688f8e19a80',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '05e8665f-5e85-4773-944b-625b548ae26a',
    ),
  );
  $terms[] = array(
    'name' => 'My case will be tried in the Penobscot or Passamaquoddy tribal court.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'a270752a-a6b6-4748-a5e4-a2560d438e0c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '921 - TRIBAL Recognized Tribes',
          'format' => NULL,
          'safe_value' => '921 - TRIBAL Recognized Tribes',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b401fe9d-9865-48b2-8326-5962c259d514',
    ),
  );
  $terms[] = array(
    'name' => 'My children have been removed from my home, or the State is threatenting to take them.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'a31a649c-85eb-491b-b607-e3f212ce1654',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd52e5dc1-9cd0-476b-b0e2-3c68bebe6c7c',
    ),
  );
  $terms[] = array(
    'name' => 'I have MaineCare but am having a problem with my coverage.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'a445e502-6456-4668-a102-8fdfdc775cce',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4764391-fa37-4ea1-90d9-dab8e6b7ae32',
    ),
  );
  $terms[] = array(
    'name' => 'My case will be tried in state court (Maine).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'a45a2de3-c794-4c01-9a63-c85523d8c0e0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b401fe9d-9865-48b2-8326-5962c259d514',
    ),
  );
  $terms[] = array(
    'name' => 'I have not been paid all the wages I earned.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-6',
    'uuid' => 'a54857de-79b1-4e87-a4bf-b57a52eea118',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I have questions about my pension or retirement fund.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'a77d9080-2a4c-4421-b8e0-2531e7cbbe32',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'I need time off related to  military service by myself or a family member.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'a83d5d54-54a3-4b27-8ed2-681910adee01',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4e783cd4-06d6-47cf-9324-5da03a344294',
    ),
  );
  $terms[] = array(
    'name' => 'Criminal & Juvenile',
    'description' => 'traffic offenses, OUI, juvenile charges, criminal and juvenile records',
    'format' => '2',
    'weight' => '3',
    'uuid' => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '0',
          'filename' => 'cori-icon.png',
          'uri' => 'public://cori-icon_2.png',
          'filemime' => 'image/png',
          'filesize' => '2009',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => 'd85aa6ed-2207-42c2-ad71-52d19a1c4dfa',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6NUQ2M0E5NEE0QzgxMTFFMzhCRkZFREQ5RDlGRUUxRjEiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6NUQ2M0E5NEI0QzgxMTFFMzhCRkZFREQ5RDlGRUUxRjEiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDo1RDYzQTk0ODRDODExMUUzOEJGRkVERDlEOUZFRTFGMSIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDo1RDYzQTk0OTRDODExMUUzOEJGRkVERDlEOUZFRTFGMSIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PtSN9zAAAARNSURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoqENHHTrqUHzAUF3+2IKaZe2ZuqoyNHUos6CaFSX6ozwtHE21ZMQEw9zMpUUFL91+/PX7z8Ho0DuPXxmoy0mJCjIyMmorSwPd/f///4u3Hv/7939wOZSHi2PRlqP3nrzWU5Pl5eZgZWGxNlD1tTd4/ubj3SevBotDRQR498wo01OVXbP39IzV+37/+WugIcfCzCzAy+Vja2Cmo3Tp9pN3n74OvENrUv2MNBSUZcUi3M1ZWJhnrzu4evcpUUFeNTkJYEqQFRcKdzPbfuTS+8/fBjLX66jIhLqaQdgcbKzZYc57Z5ZZ6qkU9iwPK5927d5ToDgbKwsQUSVEGcnr3AEDbHl7pqm2IqbU+ZsPW2dvvnjrkZOZ1o+fv49cuDWQUe9jZ5AcYIdVSlJEINTV9NHLd9uOXHz04u1AFvic7KzlCd54FHz88n3fqWsDXzOlBTtKiQrgUdC3ZAfQrQPsUHFh/tQgBzwK/v3///nrDyZGxoEs8IEF5LuPXx+/eAcp3nHlMw8rXVcLbWCZ/+DZmwFw6PyGlLbcEHV5iZW7Ts5aewBYVQKdCyzekdW8fPeJh5MdyACWpn72hjaGag+fv3366j1dHVqT4sfJwaYiKx7laQks3meuOYBcvAMV/Pz1x79gwsGzN421FPh5OIEiwKQc4mIKbGEBq9NX7z7RyaHAotFYU0GQjxsYimbaSiEuJncfv568Ys/xS3e0lIDNEr7Z6w7sOHYZGIQrd55kZWE2UJNjYgJ5QF5KBFh1qclL3Hzw4j25NSoJDgXG4PIdJz5/+6GvJsvOxsrNye5hrWtrpHbwzM0JS3cBi8wVO04Cq3ugyj9//x25cHvPyWvA2guY+SAJV1UOFBWyEsJX7z4FGkLbzARsvJ278XDVrlN8PJxaytJA6yHFu5SY4PIdJz9+QanT33z4vGb36Q9fvptqKwBbVaAihokRGPax3tZC/NxX7z779uMXbWsmYMUILM/3nrymLCMqIy4EdK6WkrSRpvzq3afRVAIz3IWbjzbsPweMfSVpUaiVTEzAJmy0lwUwxQND9+fvP7RtPb1+/3nt3jO3H700UJcHFlW3H73YeOA8VpVfvv3YfOgCUKWJliI3uEwAAmAYAxM6MO0COwVPXhIuFhgpH3FmZ2PRVpa5cZ9wVPJxc5bGe0Z4WCBXB1fuPPEvnEiPXiiwVDp3/QExCe7T1++109ZFlE+78/glXPAXraOebPD8zQdg+fXrz191ecnnbz9WT1n7kogilnGoTDawEJ8QbQzUgCTB8uvs9QfAfDZgDm3NDgl0MiZG5bPXH+yT24BtqIFp5gELaiJVAut3PnBFT+9mHtDittxQbWVpYLVJpKHA6ur7z1/ASp+uUQ8s84BNocu3nxBvqDA/Dytq82/AeqGjw46jDh116KhDRx066tBRh446lLoAIMAA4C6jlSntOrYAAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'A seller or lender is discriminating against me because of my race, color, sex, age or other illegal form of discrimination.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'abdfbc7e-e944-439b-9c4f-d503ddd91e3d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '661 - HOU Housing Discrimination',
          'format' => NULL,
          'safe_value' => '661 - HOU Housing Discrimination',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ef6ffce8-ae1e-4df0-9e72-92c9ca1a34b7',
    ),
  );
  $terms[] = array(
    'name' => 'I have lost my my occupational license or drivers license.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'acba75bd-7ecf-4a3a-90b0-0872149ef740',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'I pay my own rent (without help from a housing program).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '24fb4aa7-08e1-467c-9668-bc32d9312ad5',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with the IRS (federal income taxes).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'ad7cb45a-033e-467c-936a-09bcfad3e732',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'bad14cf3-9a7e-4e33-a94c-7685c0079e59',
    ),
  );
  $terms[] = array(
    'name' => 'I want to know whether I could get TANF if I apply.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'ae49fd33-9910-4e57-9fd1-45b0bed52e6f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9d2eba9c-cc98-4569-b093-f8a1172e9ba4',
    ),
  );
  $terms[] = array(
    'name' => 'I serve in the Guard, the Reserve, or other military service.  Or a member of my household serves in the Guard, the Reserve or other military service.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'af4345ac-4bac-4986-97f2-e286f653b28d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '57d27a87-3995-436e-ab1f-91ed08296c9f',
    ),
  );
  $terms[] = array(
    'name' => 'Family',
    'description' => 'divorce, child support, child custody, domestic abuse, adoption, guardianship',
    'format' => '2',
    'weight' => '-4',
    'uuid' => 'af936db2-1290-4648-97f9-5b53d0fc4f9a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '0',
          'filename' => 'family-icon.png',
          'uri' => 'public://family-icon.png',
          'filemime' => 'image/png',
          'filesize' => '1999',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => 'c6b99125-ee2b-40ba-b216-b1abc263f0d1',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6MUNENThEMUU0Qzg1MTFFM0ExNjZBRUU5OUFGQzk1QTYiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6MUNENThEMUY0Qzg1MTFFM0ExNjZBRUU5OUFGQzk1QTYiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDoxQ0Q1OEQxQzRDODUxMUUzQTE2NkFFRTk5QUZDOTVBNiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDoxQ0Q1OEQxRDRDODUxMUUzQTE2NkFFRTk5QUZDOTVBNiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PiC3u/wAAARDSURBVHjaYlTyKWEYCoCJYYiAUYeOWIey0M0mEQEeBxMNLg62U1fu33jwfJA61MtGrzUrkI0Vat2avWebZm36++8f8SYwC6pZ0dqV8pLCc2oT4K4EAi0lqS/ff1649XhwpVF7Y3VWFmY0QX97g0GXmfh5ODEFubk4Bp1Dr9/DknXuPn416By67/T1Y5fuIot8/vZjwvLdJBlCj8z0n4Fh1/Erf//9Z2dj/frj595T16umrL335DVJhjAOlUYJDctRH1v9EGdjeSkRDjaQLf//M3z9/pOHix3I/vnrz5dvP16++3z9/rN9p2+cu/FwwEI0ztuqPMGT+ERc0Lvi799/9M5MdkZqJXHuxKt3MtUMdzWld65XlRPvyg9lZiLNZA8rXbo6VIiPe1JpFC+sMH/59tPLd5+I0aitJEU/hwLryb6icDkJIXhhmdG26OOX78To5WBn5eZkp5NDq5N9TLUVIWxgyyi/e/mtRy/xqAc29rLalyCcwshID4eGupgAEZzbuWD7ySv38Gv59uPXjYfENkyp41AjDXlgcMK5a/edXbr9BDEav33/RT+HigvzTSyJhDfkzlx70Dx7M7HJmpWZfg7tK4oQ4ueGsB+9eFfYu+L3n79E6mVnJbZqJFodM3NXfgiwZL5y52lh34rX7z/DcjqLvqoMhP3u09f01oVAciB7od62eu6WOsD4NdSQyw5zgta/jIxl8R6M4Nz65dvP5Mb5wBAd4EaJhBAfonEOK/AKolyiPMyBEd08Z/OuE1c/f/0x8P369fvPPXv9AcgARvqcDYcgzY6UALv////XTFu/du9Z8lz5/edvKofo209fo6tnAfuTD5+//fHrT4SbGTDSgeITlu3Zcvgi2eGE3GIC1mQUOdTfwTDBx0pZRoyZGT34F205BgndgW84q8iKNWcGYG0KAQOya9EOCq0HVk7AUgLYlHny8j1FDjXVUsDqytPXHgCTJjCBkuSsPSevAROlr50+Iur//YupmW2gJnvkwh2KMhOw+ASS245e/vn7D7L4kfO3iS/V4eDB8zcXbj5CEwQm+o0HL7z9+IUih0Jcc+DMjV+oDqU/IOBQHhLHMwiCH79+08ShuLvq/8nQ9e/ffzISDFEOhYwMsmAMcX399pMMy74S3agj2aHff4CM/kNuMNAvjf4DF0A/f/0ZcIcSKEd3n7gKrJAOn78FLZUu3LYxUCXfMhYmWoXo+8/flu84CS9ET199QEmocLKz0rz1RDb4RaVkQ3uH/hkiDqV3w5kqgPhm8gA79M+ff6NRP0QdCp8UxOyW4Gy+/EdpyiBXcvg7SWQ69Ac4Hzx/8+EbuPZ/8+ELkRqPXrgNTaB//568cu/mwxeQahnYO1iz5yzxDiV2DF9bSUpTURLYFAd2GxSlRYG9Z+IbbNYGKnISwqev3r8DngTTUpIy0pC/fOfJRVLmQhlH15SMOnSQA4AAAwDek8HIUkXT0wAAAABJRU5ErkJggg==',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'I am being harassed by a neighbor or someone else.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'b0dcffab-3413-4ff6-b09b-5cea8f38a7a8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'I am disabled and need a "reasonable accommodation" from the mobile home park owner (such as handicap access).',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'b1c6db70-8f7a-4261-8560-e2e3f8d3960f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '655 - MOBILE Reasonable Accommodation',
          'format' => NULL,
          'safe_value' => '655 - MOBILE Reasonable Accommodation',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '78f5751f-e6ea-4460-984c-cb743da5c743',
    ),
  );
  $terms[] = array(
    'name' => 'I am in jail or prison and need legal help relating to my criminal offense or prison term.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'b2526120-c974-4444-aa8b-559e183a109d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f0020f81-3f84-42d3-9928-d3def15acac2',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with a former landlord.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'b2e93b7a-a04f-4f16-91be-7711e53295d6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7501a644-65bd-4e23-82af-86857bba181c',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord has given me a written notice to be out.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'b2eb7f9b-9be6-4472-a997-d591157a6e4f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '14a537c1-8f1d-4631-81d2-9492cd2fc9a4',
    ),
  );
  $terms[] = array(
    'name' => 'I am Native American and have been charged with a crime.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'b401fe9d-9865-48b2-8326-5962c259d514',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'b955c0ef-818a-4c79-8b3e-e5a3ad16cb87',
        ),
      ),
    ),
    'parent' => array(
      0 => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    ),
  );
  $terms[] = array(
    'name' => 'I have contacted the seller and can\'t come to an agreement.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'b4653bd4-61ca-4bc4-948f-80838137f4fb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '42185365-84f3-40ef-b55f-fefa3674be4d',
    ),
  );
  $terms[] = array(
    'name' => 'I am a victim of violence or sexual assault.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => 'b4bc5d14-c113-4547-9648-f9672ff6f9fb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '421 - JUV Neglect/Abuse (rep child)',
          'format' => NULL,
          'safe_value' => '421 - JUV Neglect/Abuse (rep child)',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'I have a child with a juvenile charge.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'b5a39d44-a5d1-437a-9039-2085f6017b14',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with another type of debt.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'b5d4068f-bd35-4bd1-bca9-4592203ea2dc',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4534f8df-ec3b-4dbc-85af-3143e276210b',
    ),
  );
  $terms[] = array(
    'name' => 'I have a different problem with my former employer.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'b6b430e5-90b4-4731-bdf8-3545e29bea7a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I have MaineCare and I am having a problem.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd42d6a48-e52b-4d30-928e-ba27bbc276ea',
    ),
  );
  $terms[] = array(
    'name' => 'The park owner is shutting down the mobile home park.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'b752c771-1601-4df7-917d-6d68b9388f71',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '651 - MOBILE Eviction - Home Rental',
          'format' => NULL,
          'safe_value' => '651 - MOBILE Eviction - Home Rental',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '78f5751f-e6ea-4460-984c-cb743da5c743',
    ),
  );
  $terms[] = array(
    'name' => 'I am having trouble with my home-related expenses (such as property taxes or utility bills).',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'b7770d7c-ed49-4df6-8df6-9bf4a88c3aa5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '00b8afef-bf42-4520-a1a7-e28f384bfa8c',
    ),
  );
  $terms[] = array(
    'name' => 'My employer did not pay me accrued Paid Time Off (PTO), vacation pay or sick time  when I finished working.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-5',
    'uuid' => 'b77a2787-42f9-41b0-b32e-b2915d4bbb8b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I have not been paid all the wages I earned.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'b7b76d5f-f912-4da9-9f25-37a0edfd384b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'My former landlord is suing me for unpaid rent or damages.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'b7c6bcab-7a3a-4b9b-aa5c-5400f21773ff',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b2e93b7a-a04f-4f16-91be-7711e53295d6',
    ),
  );
  $terms[] = array(
    'name' => 'I can\'t pay my bill or am facing shut-off.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '31a6da4f-a038-412b-af35-a6c39f4e908e',
    ),
  );
  $terms[] = array(
    'name' => 'They are threatening to kick me out.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'b8ecc533-188d-4e40-9dc2-56b70e0d560a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '693 - HOU Shelters',
          'format' => NULL,
          'safe_value' => '693 - HOU Shelters',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'cbad4abf-0a53-409c-b29e-383f0558c0dd',
    ),
  );
  $terms[] = array(
    'name' => 'I have another legal question or issue.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'b8ef9dd4-a081-47b0-9543-9fde95704d04',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    ),
  );
  $terms[] = array(
    'name' => 'I am Native American.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'b955c0ef-818a-4c79-8b3e-e5a3ad16cb87',
    'language' => 'en',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'maine_triage_status_groups',
  );
  $terms[] = array(
    'name' => 'I am losing some services I had before.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'b98cdc6a-3adf-4e48-9a95-1a11f7bf7c06',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '512 - HEA MaineCare Adult Elig - Med',
          'format' => NULL,
          'safe_value' => '512 - HEA MaineCare Adult Elig - Med',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    ),
  );
  $terms[] = array(
    'name' => 'Taxes',
    'description' => 'income taxes, tax credits, property taxes, payroll taxes',
    'format' => '6',
    'weight' => '3',
    'uuid' => 'bad14cf3-9a7e-4e33-a94c-7685c0079e59',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'debt-icon.png',
          'uri' => 'public://debt-icon.png',
          'filemime' => 'image/png',
          'filesize' => '1904',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '791e9653-8212-4984-a236-9c903dd2a729',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '56',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAA4CAIAAAAn5KxJAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6QTY0RTA0RjA0QzgyMTFFM0FBRERFNThGM0EyNTcxRDAiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6QTY0RTA0RjE0QzgyMTFFM0FBRERFNThGM0EyNTcxRDAiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDpBNjRFMDRFRTRDODIxMUUzQUFEREU1OEYzQTI1NzFEMCIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDpBNjRFMDRFRjRDODIxMUUzQUFEREU1OEYzQTI1NzFEMCIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PtnMZlMAAAPkSURBVHjaYlTyKWEYCoCJYYiAUYeOOnTUoaMOHXXoYHAoBzsrnM3IyKgoLQrnsjAzc3GwUW4Fs6CaFeWmKEmLFka7PXn1QV5SuCnDvzTeg4+L4/mbj7qqMkD21iOX/v37T6EVjNSq6xc1pRhrymOKz15/aMKy3YMojS7fcRJT8N///6t3nx5cmWnPqWuv339GEzxy/vbT1x8Gl0N///m7du9ZNMGVVApOUKakYgmyavdpWyM1OPfz1x+Hz90ajA79+OX7tXvPkLjf/v77NxgdysrCHOpiAucCi6f+pbsHo0N//f5T1LcSzv3x6zcVDaeaQ5mZmJoyA3xs9ZEFOxdsX7T1GHXMp0rNBASlce5hrqZogtb6Ko9evLv16OVgKZ6CnIzifayx1HuMjI0Z/roqMoPCoapy4tXJPjjbK2ysfUXh/DycA+xQdlaWnoIwoGvwqJESFWjODBxgh2aEOKjIihFU5mym6WWtO2AOBbbuEv1s0ATffPiyes8ZTMXlCV683BwD49DSOA9gIY8meO/J64aZG4FlKpq4iABPWpD9ADhUW0nKDqlmh1Tu5ZPWJDfNB7LN4loaZ21C0xLhZibIy0Vvh6YFowdP27ytWw5f1FGRzgl3crXQPnnlHpoCYJ8kzofMYpvMmklMkNfRRAO99XnxNpCsSfEFBjaQ8e3HL0yNIc4mU1bt+/v3H51CFBhgwDoTTVCQlxtITlq+5xm4sYy1TyfEz22urUi/KjQj2F5BSgRNUFSId/eJaw+fv12+49Tjl++APTtuTnZMvW8+fjl+6S6dQlQTHLlowMVMa35DErCL9+fv340HzkdUzgC2ULHmQjplJmCRJC7Eh1UK6Epgd3R2bQIPJ/vLt5+2H7uMqUZaVJBODsVVYX79/hPCsNJTNgUnRMzSFAh4uNjplOu//8TSIn71/rNfwSR/B0MtJaknL98duXAbmNus9FQwVX759pNODgUmQWA3Q1KEHyU783HJSwkv2XYcwgVmo+okb6zNAGBuo1+u11CU1FCQQElDTEzADpOnta6MmOCxi3eOL6jSwdEMXbHz1MVbj+lU4K/Zc8bf3gBrM4WdjfXdp6+c7NgHxr58/7nx4Hn6hSgw6pVkRFVlxTGl+Lg5LPWUcWlsn7/t7PWHdK3rG2duuorUiycGzN1weBW5Yyfkd+6ARc/WI5eArXc1eQmCij99/Q5sTC3YfJTscKHCsKOeqgyw+WxvrA7slmDKPnn5fs3eM8AM9PnbD0psodr4KDD36KvJADOTiCAvsFoCNp0evXh76faTO49fUcV8xtFJ21GHjjp01KGjDh116KhDyQEAAQYA7YpFvfv2o80AAAAASUVORK5CYII=',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
  );
  $terms[] = array(
    'name' => 'The firing was as the result of a drug test.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'bb5406eb-ae27-472d-b8eb-9638fcafd9c6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c2c2c551-00e7-41b2-9b1a-d8f84a7ea0af',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for TANF but was denied.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'bcbca287-7027-46c2-ba79-a6c0e8ebde4e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '712 - TANF Eligibility',
          'format' => NULL,
          'safe_value' => '712 - TANF Eligibility',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9d2eba9c-cc98-4569-b093-f8a1172e9ba4',
    ),
  );
  $terms[] = array(
    'name' => 'I have an upcoming hearing at Tax Court.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'bd659839-0029-43b1-945d-ad8097e2f149',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '241 - TAX Federal/Federal & State Taxes',
          'format' => NULL,
          'safe_value' => '241 - TAX Federal/Federal &amp; State Taxes',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad7cb45a-033e-467c-936a-09bcfad3e732',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has charged me with an overpayment.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => 'bd8cf6dc-4ede-4276-ad05-b314124d4ecd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '713 - TANF Overpayments',
          'format' => NULL,
          'safe_value' => '713 - TANF Overpayments',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3d963d5e-247f-4bbd-b000-48e6df3b917f',
    ),
  );
  $terms[] = array(
    'name' => 'I would like to get an IEP (individualized educational plan) for my child.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'bdf0a904-f26a-4fae-b6b2-6ee5c27013ff',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '131 - EDU Identification',
          'format' => NULL,
          'safe_value' => '131 - EDU Identification',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '04882722-da8d-4136-9ece-55120acf9467',
    ),
  );
  $terms[] = array(
    'name' => 'I live in a mobile home park and there are bad park conditions.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'bfd9a08e-40f5-417f-a3ef-771de0571b91',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '654 - MOBILE Warranty Habit/Park Cond',
          'format' => NULL,
          'safe_value' => '654 - MOBILE Warranty Habit/Park Cond',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f35268de-da45-48e4-9a9b-8af3959f47e5',
    ),
  );
  $terms[] = array(
    'name' => 'I received rental assistance and am concerned that this could interfere with my eligiblity for rental assistance in the future.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'c03c81bb-8818-454e-ab64-67f85941188f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '613 - FEDSUB Security Deposit',
          'format' => NULL,
          'safe_value' => '613 - FEDSUB Security Deposit',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e216d8c5-2424-43dc-af2b-5216fb219b7b',
    ),
  );
  $terms[] = array(
    'name' => 'I missed work because I was in the military, or a family member was going on or returning from active duty.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'c126b9fd-9334-4de4-83d5-c6b22074040e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '27d8719c-f29d-4cd9-b784-cf600608e38d',
    ),
  );
  $terms[] = array(
    'name' => 'I want to apply for a tax abatement.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'c129e348-61c9-46f9-8985-6be7e117d19c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '18367075-e181-40fd-a0ad-76e15674d2c0',
    ),
  );
  $terms[] = array(
    'name' => 'I have not yet taken any legal action.  I want to talk to a lawyer first.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'c1c87fe6-4ed2-48f5-ab23-84e3a61b3bd5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '44773640-bbcf-4d01-95b6-2397f47e8bc3',
    ),
  );
  $terms[] = array(
    'name' => 'I have a complaint against a utility supplier.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'c1f22ad2-cfb7-44d9-848b-90470d6c368c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '31a6da4f-a038-412b-af35-a6c39f4e908e',
    ),
  );
  $terms[] = array(
    'name' => 'I am not happy with the help I am getting at school.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => 'c209273d-708f-48e9-a2fb-8e0bc7b1f8af',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '134 - EDU Complaint',
          'format' => NULL,
          'safe_value' => '134 - EDU Complaint',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has sent me paperwork about paying child support and I don\'t believe that I am the child\'s father.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'c21b4b68-74b3-474f-9249-82d91444dffe',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9f102d50-cb84-41ed-888e-ecd08e327177',
    ),
  );
  $terms[] = array(
    'name' => 'I was fired because my employer said I used drugs.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'c2c2c551-00e7-41b2-9b1a-d8f84a7ea0af',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '66b0e165-af42-404e-a74a-aea285e61456',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem with LIHEAP benefits.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => 'c3cc0232-ced2-4705-9e3d-c179db39364d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '783 - INC Fuel Assistance',
          'format' => NULL,
          'safe_value' => '783 - INC Fuel Assistance',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '20d8f25e-49de-42f3-aca2-75333b3745b0',
    ),
  );
  $terms[] = array(
    'name' => 'I was hurt on the job or have an illness caused by my job.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-5',
    'uuid' => 'c41c270b-14ba-4897-837f-4ceb4cf831e2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem getting government benefits or services (such as Food Stamps, TANF, MaineCare, etc.) because of my status as a Native American.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'c47066f4-592c-4254-95e0-8542a8253fa5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '851 - IND Civil Rights',
          'format' => NULL,
          'safe_value' => '851 - IND Civil Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    ),
  );
  $terms[] = array(
    'name' => 'I think that my Constitutional rights have been violated in some other way.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'c4f0831a-1b1c-4901-afce-9d18b0985ee6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2391ff3e-3792-4a5f-a8b6-15722faf504e',
    ),
  );
  $terms[] = array(
    'name' => 'Disability Rights',
    'description' => 'legal issues stemming from the fact that you have a disability',
    'format' => '2',
    'weight' => '-13',
    'uuid' => 'c556b483-3dbf-42e7-9337-0cc0a0a98d4c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => '1',
          'filename' => 'disability.png',
          'uri' => 'public://disability.png',
          'filemime' => 'image/png',
          'filesize' => '486',
          'status' => '1',
          'timestamp' => NULL,
          'uuid' => '933a4073-a534-4cba-933e-868c042bf3e5',
          'alt' => '',
          'title' => '',
          'width' => '56',
          'height' => '50',
          'uuid_features_file_data' => 'iVBORw0KGgoAAAANSUhEUgAAADgAAAAyCAYAAAAJHRh4AAAAAXNSR0IArs4c6QAAAAZiS0dEAP8A/wD/oL2nkwAAAAlwSFlzAAALEwAACxMBAJqcGAAAAAd0SU1FB94LBA4tO4ft73gAAAFmSURBVGje7Zk7bgIxEIZnrb0BF1hBESm3oKIJZ6CgTQkXoLUoqBFFzmCkdCAuQURhskofRBMh8VinSRGFR4Cd8Usz5a7W688z83vGTqpPHQMRm4DIjQEZkAEZMFxAY4r8cz59cAmYUg2slQQAyABgAQBQa3bj8eAP3L/POAdDAzSmyKMGTBKRRQF4SlBciUxC2U0YU+Srt1mj8lhf8DbBKsqADBiloaroveUYpQAJ13DUdWppwGK/fSk7QW89eNhueu+vg1aZMbLGc8/bHDznuVqze/TO1UafYsJdgrg2jLEXQtiA432QUFFRAH1qj6x1E7dA/vWaVhJtgbwI0SAqGapc1EqCVhJ2X+t20ICnvPg7dD8mw1GwgFpJshM34UsoLsf9zFsVxVQ9bAFK7/0pxoZsoyJy1g/auqsg6yYovnNyZIHlCaocFj5MzPtKpswEqYty9LsJV42tNUBueBmQARmQAWOybxqaljR4B3SyAAAAAElFTkSuQmCC',
        ),
      ),
    ),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '66772567-a963-4825-8c2b-f22eba0fabc6',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'I did not get rental assistance (such as Section 8 or through a Housing Authority). I just want my deposit back.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'c5a045f1-fa46-4f80-941b-df52be347780',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e216d8c5-2424-43dc-af2b-5216fb219b7b',
    ),
  );
  $terms[] = array(
    'name' => 'My legal issue is not related to my status as a servicemember.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'c5cde29c-2d68-406e-b140-88fedb7352d4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'af4345ac-4bac-4986-97f2-e286f653b28d',
    ),
  );
  $terms[] = array(
    'name' => 'I have an adult criminal record that I want to fix or get rid of ("expunged").',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'c63dd1ca-abc4-46b8-929f-3b4fe3b09a81',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for help but they turned me down.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'c685aa6d-3b8e-4e48-a64e-145023b15464',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '781 - INC General Assistance (GA)',
          'format' => NULL,
          'safe_value' => '781 - INC General Assistance (GA)',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
    ),
  );
  $terms[] = array(
    'name' => 'I was denied and filed an appeal and have been denied again.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'c6ec958c-bd4d-49ed-be80-75f1e9036b61',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e64887db-bf03-4362-9ee9-0f5ff447d301',
    ),
  );
  $terms[] = array(
    'name' => 'I want to appeal the town\'s decision on my tax abatement application.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'c7ef2338-3da2-4067-87db-66504afced2e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '623 - HOM Tax Abatements',
          'format' => NULL,
          'safe_value' => '623 - HOM Tax Abatements',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '18367075-e181-40fd-a0ad-76e15674d2c0',
    ),
  );
  $terms[] = array(
    'name' => 'I need legal help but don’t see my issue on this list.',
    'description' => '',
    'format' => '2',
    'weight' => '3',
    'uuid' => 'c7f980be-2300-42df-b749-44b6d34baab9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '499 - JUV Other Juvenile',
          'format' => NULL,
          'safe_value' => '499 - JUV Other Juvenile',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'I want to know how to protect myself from identity theft.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'c8281cf6-7ead-461d-a451-4e5a06ec2e8b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '10203af7-8605-4fb6-ba14-617fdae48265',
    ),
  );
  $terms[] = array(
    'name' => 'My former employer is lying about my job performance.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'c87aea9d-abd9-4fff-bf89-67dbcede5ccb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '80039820-9209-4d59-9d50-b30b516d8e35',
    ),
  );
  $terms[] = array(
    'name' => 'My legal issue relates to applying for a job and being rejected.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'c997ca59-41cd-49f2-9005-4f39ad8454d5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'I have a complaint about my electric, natural gas, water or home telephone company.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'c9b5c6c2-ad41-47d4-94ad-679a8ffed777',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c1f22ad2-cfb7-44d9-848b-90470d6c368c',
    ),
  );
  $terms[] = array(
    'name' => 'I have a complaint about my heating oil, propane or firewood supplier.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'c9bbb448-491a-485a-9e23-60141153898d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c1f22ad2-cfb7-44d9-848b-90470d6c368c',
    ),
  );
  $terms[] = array(
    'name' => 'I have received notices from the bank but not court papers.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'cb3d136c-bb8e-4035-b599-999fcc0ec496',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '970d6f59-bbc4-4a96-966e-fa74c6d45ffd',
    ),
  );
  $terms[] = array(
    'name' => 'I am a grandparent with legal issues concerning my grandchildren.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'cb57e142-31c3-4930-ad4a-ab029ac809d2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    ),
  );
  $terms[] = array(
    'name' => 'I live in a group home or a homeless shelter.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'cbad4abf-0a53-409c-b29e-383f0558c0dd',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '7501a644-65bd-4e23-82af-86857bba181c',
    ),
  );
  $terms[] = array(
    'name' => 'I received a letter from DHHS saying I am being accused of neglecting and/or abusing a child.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'cc7c5b88-1c39-4587-bcf1-9e8781f1202c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '53467ab1-c9d5-4c87-8016-e79c61a95c63',
    ),
  );
  $terms[] = array(
    'name' => 'I was fired. I think this was unfair and I want to challenge the firing.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => 'ccaaba92-32c5-437d-958e-3c6b04895208',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I\'m worried about a foreclosure, or the bank is threatening to foreclose on my home.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => 'cd2f0b1b-ed39-4248-b5a4-23ddacf6099d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '00b8afef-bf42-4520-a1a7-e28f384bfa8c',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS is not keeping me informed about what is going on with my kids.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'cd357a16-1da6-4d90-bd41-3d115999ec9b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd52e5dc1-9cd0-476b-b0e2-3c68bebe6c7c',
    ),
  );
  $terms[] = array(
    'name' => 'I have been sued in District Court for some other kind of debt.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'cd3805eb-d076-41b8-859f-42460c9fa8a9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'I have questions regarding funeral arrangements I agreed to.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'cd41d4e9-6945-4e6b-a60e-fcec8970fbed',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b5d4068f-bd35-4bd1-bca9-4592203ea2dc',
    ),
  );
  $terms[] = array(
    'name' => 'I need to know if I should declare bankruptcy.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'cd487bf1-3907-44cb-9212-f60874450ed9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '068ab1a5-8bd4-4286-80b6-0e1f05b690a5',
    ),
  );
  $terms[] = array(
    'name' => 'I want to change my DHHS child support order.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'cd761806-59c1-4a6b-a713-79485ab1e4c8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9f102d50-cb84-41ed-888e-ecd08e327177',
    ),
  );
  $terms[] = array(
    'name' => 'My employer wants me to sign a severance agreement.',
    'description' => '',
    'format' => '2',
    'weight' => '-7',
    'uuid' => 'cdde3137-5c88-43ba-b6ff-af2b35cf1f1d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '259 - EMP Other Employee Rights',
          'format' => NULL,
          'safe_value' => '259 - EMP Other Employee Rights',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '6a0d0d5d-e848-4586-a2b0-f433a62d4626',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem with property tax abatement.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'cea1a054-32a5-407a-aa5a-3751682604b3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '18367075-e181-40fd-a0ad-76e15674d2c0',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord has told me verbally that he wants me out.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'ced7e5bb-cb85-4951-b0c7-9f38cac471c1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '14a537c1-8f1d-4631-81d2-9492cd2fc9a4',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with a divorce.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'cedfc45d-bd0a-4fd3-b641-80fab7a2654b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '39d64169-94d4-46cf-ae79-87220c874bbf',
    ),
  );
  $terms[] = array(
    'name' => 'I have health insurance through a private company or health co-op; I have a question or problem about my coverage.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'd0593461-e989-4aa2-a2d0-cb41210b6450',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem with crossing the U.S./Canada border.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'd11bf5a3-21be-4eac-9256-f8ee1aedf082',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '922A - TRIBAL Jay Treaty',
          'format' => NULL,
          'safe_value' => '922A - TRIBAL Jay Treaty',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    ),
  );
  $terms[] = array(
    'name' => 'I have another question about Protection from Abuse orders.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'd248edd1-19b7-418a-ad7b-94323be695ea',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    ),
  );
  $terms[] = array(
    'name' => 'I have a land installment contract or a rent-to-own contract and I\'m having a problem.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'd2746cd3-57d9-4a0b-ab29-0ec22922da45',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '628 - HOM Land Installment Contract',
          'format' => NULL,
          'safe_value' => '628 - HOM Land Installment Contract',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ef6ffce8-ae1e-4df0-9e72-92c9ca1a34b7',
    ),
  );
  $terms[] = array(
    'name' => 'My child is unable to enroll in school or attend school.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'd2b4862d-071b-4205-9379-cc186a689100',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '121 - EDU Readmission',
          'format' => NULL,
          'safe_value' => '121 - EDU Readmission',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'I think that I am being harassed for other reasons, such as the boss doesn\'t like me, or my co-workers are hard to get along with.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'd2ec1869-1d78-4e7e-bc49-514dac650a68',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3bda5ac9-46c2-4ecd-a417-2a450b61cc2f',
    ),
  );
  $terms[] = array(
    'name' => 'I am a grandparent or other relative and can\'t get information about the children.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'd307aa66-d7fc-4577-9710-21787eaccb78',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd52e5dc1-9cd0-476b-b0e2-3c68bebe6c7c',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with DHHS about child support, custody or alleged child abuse.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'd36972e9-6cc2-44d8-8510-21475f663daf',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    ),
  );
  $terms[] = array(
    'name' => 'The problem is with my electric bill.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'd3a0f05f-41c0-4193-aeff-92c41a438f03',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b882bc94-80cd-439c-92a0-0f26eb7b0794',
    ),
  );
  $terms[] = array(
    'name' => 'I have been laid off and want to know about training benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'd429f0fc-20f6-4756-b68e-40fc4c3807a9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e36b4eb3-ee6b-438b-88df-523f064c6dde',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with MaineCare (Medicaid)',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-5',
    'uuid' => 'd42d6a48-e52b-4d30-928e-ba27bbc276ea',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a different problem with my private insurance.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'd4951165-27ae-4bb1-ade3-12d91011d7a0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd0593461-e989-4aa2-a2d0-cb41210b6450',
    ),
  );
  $terms[] = array(
    'name' => 'I have run away from home and want to know my rights.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'd4cf083f-648e-467f-87d0-f509c3104c45',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'I am being bullied at school.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'd511b1f3-afe8-4abb-8918-61f72f8f5690',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '191 - EDU Bullying/Harassment',
          'format' => NULL,
          'safe_value' => '191 - EDU Bullying/Harassment',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '88e3b096-92fa-450a-8287-94d3b6a3af1f',
    ),
  );
  $terms[] = array(
    'name' => 'I am having a problem getting a job or being hired because the employer wants government documents I don’t have.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'd51597db-f796-4023-8c6c-4f548d95ca44',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '211 - EMP Job Discrimination',
          'format' => NULL,
          'safe_value' => '211 - EMP Job Discrimination',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9fd6d3fb-9b3d-4e32-8e66-e6c631099c45',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS has been notified (or should be notified) about alleged child abuse or neglect..',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'd52e5dc1-9cd0-476b-b0e2-3c68bebe6c7c',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd36972e9-6cc2-44d8-8510-21475f663daf',
    ),
  );
  $terms[] = array(
    'name' => 'I do have a past criminal conviction; the conviction information is correct.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'd6753708-a06d-47c6-a1cd-81918a994439',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'df7011b5-6ba7-45cd-9b5d-66b5b553c409',
    ),
  );
  $terms[] = array(
    'name' => 'I am disabled or over 60 and want to apply for benefits.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'd69ab0f3-571c-478f-a34c-8ade6e7083d9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e64887db-bf03-4362-9ee9-0f5ff447d301',
    ),
  );
  $terms[] = array(
    'name' => 'My complaint is against a doctor or other medical professional.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'd6e2e754-5bcb-49c6-af69-e0a2e77048b5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '07c63bd5-2464-4430-a3a9-8a49c64e5765',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e02015ef-b772-42f5-9e2c-a7f959a07c10',
    ),
  );
  $terms[] = array(
    'name' => 'I have another job related question or issue that I don\'t see on this list.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'd74c4d8d-6d33-49a9-af19-63ad59f8fcde',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'I bought items on rent-to-own plan and am having problems.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'd7892a7f-855b-4edb-a448-aa33c849a7b6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '201ece9f-b22c-4e8e-ab07-c03e7c1dc53e',
    ),
  );
  $terms[] = array(
    'name' => 'DHHS is either not collecting the support owed to me or is not paying me what is collected.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'd81e33a2-9e6f-431b-9eb4-4961a0c0d779',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'eb6da79f-0133-4f15-8053-f1f9cbf7b134',
    ),
  );
  $terms[] = array(
    'name' => 'I am not married. I need help with my "parental rights" (such as child custody, visitation and child support).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'd8246bcd-9555-47b3-826c-4526969864b3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '39d64169-94d4-46cf-ae79-87220c874bbf',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord won\'t give back my personal belongings (such as clothes, furniture, TV).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'd8448096-2b4e-47c7-817e-a2204b60fb24',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b2e93b7a-a04f-4f16-91be-7711e53295d6',
    ),
  );
  $terms[] = array(
    'name' => 'I get help with rent from some other program (such as HUD or Rural Housing).',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'd9479e8f-60bf-49f2-b898-33fe8afcd0c9',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => 'f038138e-92ac-4103-a846-4a8dd46b6547',
        ),
      ),
    ),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '24fb4aa7-08e1-467c-9668-bc32d9312ad5',
    ),
  );
  $terms[] = array(
    'name' => 'I want to get a "Protection from Abuse" order to protect me or my children.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'dace9efc-5677-4311-b6d7-66f11d8c704d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    ),
  );
  $terms[] = array(
    'name' => 'Tax Eligibility',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => 'dbeb39e9-0e14-48ee-967d-f02f20ecd598',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'triage_income_eligibility',
    'field_pov_range' => array(
      'und' => array(
        0 => array(
          'value' => '0,250,0',
          'format' => NULL,
          'safe_value' => '0,250,0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'I am the child\'s father but need help defending against DHHS collections.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'dcaf8906-0ca9-491e-a94a-e5b3b2b1381e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '9f102d50-cb84-41ed-888e-ecd08e327177',
    ),
  );
  $terms[] = array(
    'name' => 'My complaint is against a lawyer.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'dcbfb513-25bd-4d94-b28b-a5d53af75ec0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e02015ef-b772-42f5-9e2c-a7f959a07c10',
    ),
  );
  $terms[] = array(
    'name' => 'I am struggling with other kinds of debt.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'dd9cce3e-5299-495b-968d-e516b6acc384',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b5d4068f-bd35-4bd1-bca9-4592203ea2dc',
    ),
  );
  $terms[] = array(
    'name' => 'I missed work because of illness or a family member’s illness.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'dde9aa2c-b73a-44e6-8bee-cef3b26ceda4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '27d8719c-f29d-4cd9-b784-cf600608e38d',
    ),
  );
  $terms[] = array(
    'name' => 'I need to apply for benefits because I lost my job.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'de934714-cdfb-4476-9a1e-5c3d1c3d6896',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'I was not hired because the employer\'s background check showed a criminal conviction.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'df7011b5-6ba7-45cd-9b5d-66b5b553c409',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c997ca59-41cd-49f2-9005-4f39ad8454d5',
    ),
  );
  $terms[] = array(
    'name' => 'I have children in my home.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'dfd08a46-a8e5-49be-9994-efff293b2543',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'dace9efc-5677-4311-b6d7-66f11d8c704d',
    ),
  );
  $terms[] = array(
    'name' => 'I have a complaint against a lawyer, a doctor or other professional.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'e02015ef-b772-42f5-9e2c-a7f959a07c10',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'My problem concerns another kind of tax.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'e0292fc9-7c7d-476b-b893-6f7f5b5b49be',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'bad14cf3-9a7e-4e33-a94c-7685c0079e59',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord won\'t return my security deposit.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'e216d8c5-2424-43dc-af2b-5216fb219b7b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b2e93b7a-a04f-4f16-91be-7711e53295d6',
    ),
  );
  $terms[] = array(
    'name' => 'I am an adult with continuing education issues.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'e36b4eb3-ee6b-438b-88df-523f064c6dde',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '45bbeff5-0de4-493d-bd09-8000b96af17a',
    ),
  );
  $terms[] = array(
    'name' => 'I applied for free care and was denied.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'e38589c2-d79a-43f0-98f3-491d75fc1df2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '599 - HEA Other Health',
          'format' => NULL,
          'safe_value' => '599 - HEA Other Health',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e74b20bd-de39-4cab-8883-7936192242ed',
    ),
  );
  $terms[] = array(
    'name' => 'There are bad conditions at the property where my mobile home is located.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'e3a75adb-0bcb-47dc-ac7c-21a8439cec9e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '654 - MOBILE Warranty Habit/Park Cond',
          'format' => NULL,
          'safe_value' => '654 - MOBILE Warranty Habit/Park Cond',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5290eb9a-1b0b-4e91-b0ad-77644b11bf29',
    ),
  );
  $terms[] = array(
    'name' => 'I am being abused or neglected by a parent or other family member.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => 'e405f165-317a-4fdb-b2d0-f92ce1208c09',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '421 - JUV Neglect/Abuse (rep child)',
          'format' => NULL,
          'safe_value' => '421 - JUV Neglect/Abuse (rep child)',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '348cdb2a-b0b8-43d2-a5d2-891c02d03f8d',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with an adoption or guardianship.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'e46e5a74-85bb-4b73-8ea7-feb61d39955b',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem or question about MaineCare.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-5',
    'uuid' => 'e4764391-fa37-4ea1-90d9-dab8e6b7ae32',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'I am an adult who is being abused by a family member or former partner.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'af936db2-1290-4648-97f9-5b53d0fc4f9a',
    ),
  );
  $terms[] = array(
    'name' => 'I have student loan payment issues.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'e4bd91b5-27ce-4897-b002-477c6bea3f5f',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '45bbeff5-0de4-493d-bd09-8000b96af17a',
    ),
  );
  $terms[] = array(
    'name' => 'I have run away from home and need other kinds of help.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'e6119b6a-3d5e-4e41-9247-4420aa9777cf',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '432 - JUV Runaway',
          'format' => NULL,
          'safe_value' => '432 - JUV Runaway',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd4cf083f-648e-467f-87d0-f509c3104c45',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with disability or old age benefits (SSI or SSDI).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'e64887db-bf03-4362-9ee9-0f5ff447d301',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'eb02b3f2-6c2c-469d-9f0e-001edddbbfde',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with getting into the PaS program.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'e66925a4-3883-46ce-b7da-62d1db36feb3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '719 - TANF Parents as Scholars',
          'format' => NULL,
          'safe_value' => '719 - TANF Parents as Scholars',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '05e8665f-5e85-4773-944b-625b548ae26a',
    ),
  );
  $terms[] = array(
    'name' => 'Can I get "free care" from a hospital?',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'e74b20bd-de39-4cab-8883-7936192242ed',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4120096d-a572-4152-9528-32b2a6d0187c',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with drafting a will or dealing with the death of my spouse.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'e756064d-df92-4875-87f8-acbc9fa01840',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'I don\'t see my job-related question or issue listed here. I have another type of job issue.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'e7e307c2-ac2e-49c8-8efc-7127e7a4e6ab',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '86a0f533-382a-4e9f-bdd3-03a5ee408067',
    ),
  );
  $terms[] = array(
    'name' => 'I reported an injury to my employer but he did not report it to the Workers Comp. Commission.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'e8a79645-4da3-4482-a21c-0d4b194d56fc',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c41c270b-14ba-4897-837f-4ceb4cf831e2',
    ),
  );
  $terms[] = array(
    'name' => 'I have applied for Food Stamps but haven\'t gotten an answer from DHHS.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'e8f65a57-5966-4a36-ace1-942486ae7817',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '731 - SNAP General',
          'format' => NULL,
          'safe_value' => '731 - SNAP General',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '558cd122-db93-4f43-adc9-be37f59ff004',
    ),
  );
  $terms[] = array(
    'name' => 'I need help with Social Security benefits.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'eb02b3f2-6c2c-469d-9f0e-001edddbbfde',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '34ae25af-3b2f-48ea-a674-aebdb22a467c',
    ),
  );
  $terms[] = array(
    'name' => 'I have a DHHS child support order but am having trouble getting the support due.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'eb6da79f-0133-4f15-8053-f1f9cbf7b134',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f0ad725c-b9cc-46f3-ac41-dd66d9924f2d',
    ),
  );
  $terms[] = array(
    'name' => 'I am being involuntarily committed or forced to take medication.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'eb9aa145-cd47-4aed-a843-31bb756c94ba',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8733c819-ac49-4a50-8655-8606946aea67',
    ),
  );
  $terms[] = array(
    'name' => 'I have another problem with my landlord or the housing authority.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => 'ec34d9f7-ffaa-4973-808a-c0e80e41a2b7',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '639 - PRIV Other Private Landlord/Tenant',
          'format' => NULL,
          'safe_value' => '639 - PRIV Other Private Landlord/Tenant',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f038138e-92ac-4103-a846-4a8dd46b6547',
    ),
  );
  $terms[] = array(
    'name' => 'I have a juvenile record that I want to keep private.',
    'description' => '',
    'format' => 'full_html',
    'weight' => '0',
    'uuid' => 'ec828947-00b4-41f8-b338-e6d82b3d19c8',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f39a9ae3-9929-4362-95d8-3e770f66eecc',
    ),
  );
  $terms[] = array(
    'name' => 'My child has discipline problems at school.',
    'description' => '',
    'format' => '2',
    'weight' => '-4',
    'uuid' => 'eca86973-411c-4cdb-aeeb-5d5e6683ce42',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '129 - EDU Other Disciplinary Action',
          'format' => NULL,
          'safe_value' => '129 - EDU Other Disciplinary Action',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'I am having another type of problem with the mobile home park.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'edf6f355-b434-413d-9178-053be35d40c7',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '78f5751f-e6ea-4460-984c-cb743da5c743',
    ),
  );
  $terms[] = array(
    'name' => 'I am having another type of problem with the property where my mobile home is located.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'ee4272e2-15e2-420c-81fd-6e0c03f57484',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5290eb9a-1b0b-4e91-b0ad-77644b11bf29',
    ),
  );
  $terms[] = array(
    'name' => 'Someone is abusing me or taking undue advantage of me.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'ef56dd65-a6ad-4243-9dd1-f100be9b5933',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '818766eb-903a-4a3b-8031-be228d441534',
    ),
  );
  $terms[] = array(
    'name' => 'I am disabled and need a "reasonable accommodation" from the property owner (such as handicap access).',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'ef630320-dc13-4260-8b9b-7285cac00897',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '655 - MOBILE Reasonable Accommodation',
          'format' => NULL,
          'safe_value' => '655 - MOBILE Reasonable Accommodation',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '5290eb9a-1b0b-4e91-b0ad-77644b11bf29',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with trying to buy a home.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'ef6ffce8-ae1e-4df0-9e72-92c9ca1a34b7',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '00b8afef-bf42-4520-a1a7-e28f384bfa8c',
    ),
  );
  $terms[] = array(
    'name' => 'I am currently in jail or prison.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '3',
    'uuid' => 'f0020f81-3f84-42d3-9928-d3def15acac2',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    ),
  );
  $terms[] = array(
    'name' => 'I want to know whether I could get Food Stamps if I apply.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'f016b1ae-a0af-4d09-86a2-cbfecfe0184e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '558cd122-db93-4f43-adc9-be37f59ff004',
    ),
  );
  $terms[] = array(
    'name' => 'I have a Section 8 voucher that helps with my rent.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'f038138e-92ac-4103-a846-4a8dd46b6547',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '24fb4aa7-08e1-467c-9668-bc32d9312ad5',
    ),
  );
  $terms[] = array(
    'name' => 'My issue concerns child support.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'f0ad725c-b9cc-46f3-ac41-dd66d9924f2d',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'd36972e9-6cc2-44d8-8510-21475f663daf',
    ),
  );
  $terms[] = array(
    'name' => 'I believe that I was fired for reporting unsafe or illegal behavior (such as unsafe working conditions or sexual harassment).',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-3',
    'uuid' => 'f105ed23-8cc9-4b8a-a7dc-26e52a37ac11',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '66b0e165-af42-404e-a74a-aea285e61456',
    ),
  );
  $terms[] = array(
    'name' => 'My legal issue relates to my current job.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'f12058eb-6666-415f-bbe0-11850e9e92a0',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4a7b07b2-fd2b-4c5e-99de-1f0169029d6c',
    ),
  );
  $terms[] = array(
    'name' => 'I have a different problem with the mobile home park .',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'f127adc6-7255-4488-95c3-e39b531a2948',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'f35268de-da45-48e4-9a9b-8af3959f47e5',
    ),
  );
  $terms[] = array(
    'name' => 'The home is my second home, not my primary residence.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'f1a65538-f6bb-42ba-87f3-c195832ed2ae',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'cd2f0b1b-ed39-4248-b5a4-23ddacf6099d',
    ),
  );
  $terms[] = array(
    'name' => 'I tried to apply for help from the town but they wouldn\'t let me fill out an application.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-2',
    'uuid' => 'f228ebf3-3368-436d-8db8-adcde1847406',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
    ),
  );
  $terms[] = array(
    'name' => 'My landlord has shut off some or all of my utilities.',
    'description' => '',
    'format' => '2',
    'weight' => '-3',
    'uuid' => 'f266c94a-84d7-4ae1-8f2c-849c1d705b27',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '632 - PRIV Warranty of Habitability',
          'format' => NULL,
          'safe_value' => '632 - PRIV Warranty of Habitability',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I need to schedule time off for religious reasons.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'f26d0d3c-ce0e-415e-9a68-afd61c15f5e7',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4e783cd4-06d6-47cf-9324-5da03a344294',
    ),
  );
  $terms[] = array(
    'name' => 'I have been denied coverage for a specific medicine or medical service that I need.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'f2dc8aae-c0a0-4440-8b8c-544d1951bd85',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '512 - HEA MaineCare Adult Elig - Med',
          'format' => NULL,
          'safe_value' => '512 - HEA MaineCare Adult Elig - Med',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'b6caf81a-9fb4-47a9-91d1-45990e816f0b',
    ),
  );
  $terms[] = array(
    'name' => 'I live in a mobile home park.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'f35268de-da45-48e4-9a9b-8af3959f47e5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'ad0d6b01-9b64-404b-91c0-830b15af7995',
    ),
  );
  $terms[] = array(
    'name' => 'I have a problem with my EBT card.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '1',
    'uuid' => 'f35ad204-77bb-41f8-9947-08287e0b9468',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '3d963d5e-247f-4bbd-b000-48e6df3b917f',
    ),
  );
  $terms[] = array(
    'name' => 'I have issues with ASPIRE or PaS programs.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'f3784360-954a-477a-a1aa-7714fcf4b19a',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e36b4eb3-ee6b-438b-88df-523f064c6dde',
    ),
  );
  $terms[] = array(
    'name' => 'I was getting benefits but I was cut off.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'f38ed856-7b26-4d9e-9d4b-eac63709713e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e64887db-bf03-4362-9ee9-0f5ff447d301',
    ),
  );
  $terms[] = array(
    'name' => 'I am under 18 and have a problem with the juvenile justice system.',
    'description' => '',
    'format' => '2',
    'weight' => '-1',
    'uuid' => 'f39a9ae3-9929-4362-95d8-3e770f66eecc',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(
      'und' => array(
        0 => array(
          'tid' => '3257eaec-0884-4b2a-8348-02ecf15d27c9',
        ),
      ),
    ),
    'parent' => array(
      0 => 'a99e1e92-20f9-4f9a-b221-10e856b68208',
    ),
  );
  $terms[] = array(
    'name' => 'The town gave me help but I think the amount they gave me was wrong.',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'f3b50506-56b5-46fc-9125-959aa0d3e3e4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '781 - INC General Assistance (GA)',
          'format' => NULL,
          'safe_value' => '781 - INC General Assistance (GA)',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '1156fed3-26b5-4264-8dc9-d399f3947f5b',
    ),
  );
  $terms[] = array(
    'name' => 'My child is being bullied at school.',
    'description' => '',
    'format' => '2',
    'weight' => '-2',
    'uuid' => 'f5485857-f3eb-4bfd-87c1-aed372f5de59',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(
      'und' => array(
        0 => array(
          'value' => '191 - EDU Bullying/Harassment',
          'format' => NULL,
          'safe_value' => '191 - EDU Bullying/Harassment',
        ),
      ),
    ),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '0d003fff-1cb0-41a9-b0f8-6a31e6b0d150',
    ),
  );
  $terms[] = array(
    'name' => 'I have another kind of tax problem.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'f6454d29-a887-4ae6-bda0-f04df3d03426',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e0292fc9-7c7d-476b-b893-6f7f5b5b49be',
    ),
  );
  $terms[] = array(
    'name' => 'I am the victim of human trafficking.',
    'description' => '',
    'format' => '2',
    'weight' => '1',
    'uuid' => 'f7cb1eb2-1be2-47be-95d6-2c059de706f4',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(
      'und' => array(
        0 => array(
          'value' => '0',
        ),
      ),
    ),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'I want to complain to a licensing board or government oversight agency.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'f9fdb7ee-4af7-43ba-93b2-37e06b9ec1b5',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '07c63bd5-2464-4430-a3a9-8a49c64e5765',
    ),
  );
  $terms[] = array(
    'name' => 'I am the parent of a child, and someone else is trying to get guardianship of my child.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'fc1ebe4f-14c2-4ed9-a564-d332ad2b5e92',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '8dc89d9d-e5da-443a-a3ab-d5049b8e6280',
    ),
  );
  $terms[] = array(
    'name' => 'I have a complaint about another company (such as cable, mobile, internet).',
    'description' => '',
    'format' => '2',
    'weight' => '0',
    'uuid' => 'fc2eb6f0-303d-4fb4-967b-f33a83367102',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'c1f22ad2-cfb7-44d9-848b-90470d6c368c',
    ),
  );
  $terms[] = array(
    'name' => 'I am a student; my school has violated my individual rights (for example, illegal locker search, gay rights discrimination, etc.)',
    'description' => NULL,
    'format' => NULL,
    'weight' => '-1',
    'uuid' => 'fc461aa9-b1f7-41a8-a8c8-1fdd4c0f031e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '2391ff3e-3792-4a5f-a8b6-15722faf504e',
    ),
  );
  $terms[] = array(
    'name' => 'I can\'t find my problem anywhere on your list.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'fcc2ddc3-6e44-4861-b730-c98669e812b3',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '160ce6b4-b52c-4b61-9683-4a80b5f6d07e',
    ),
  );
  $terms[] = array(
    'name' => 'The harassment was not related to my sex, pregnancy, sexual orientation, race, color, disability, religion, age, ancestry, national origin, or reporting unsafe or illegal behavior.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'fd026492-8214-4c76-8df2-27a8ee61b8ce',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '58ac6fd2-954d-41c6-9706-81d95c49fdf6',
    ),
  );
  $terms[] = array(
    'name' => 'Can I get help with prescription drug coverage?',
    'description' => NULL,
    'format' => NULL,
    'weight' => '0',
    'uuid' => 'fd2b84a8-1ff5-464f-b3b6-897d1b2b0175',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '4120096d-a572-4152-9528-32b2a6d0187c',
    ),
  );
  $terms[] = array(
    'name' => 'I have another type of family-related legal issue.',
    'description' => '',
    'format' => '2',
    'weight' => '2',
    'uuid' => 'fd55042b-8fa2-49e9-b73f-d747e8771702',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => '154236f4-a8ea-42c5-80f2-ba0da320da43',
    ),
  );
  $terms[] = array(
    'name' => 'I\'m not looking for help with the abuse issues but with another family law issue.',
    'description' => NULL,
    'format' => NULL,
    'weight' => '2',
    'uuid' => 'fe18474f-0cba-4352-869a-abf49e6f8ff6',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'me_triage',
    'field_icon' => array(),
    'field_triage_extra' => array(),
    'field_triage_keep_private' => array(),
    'field_triage_ref_me_triage' => array(),
    'field_triage_status_me_triage' => array(),
    'parent' => array(
      0 => 'e4a08731-c1c4-4eb4-b885-cdc3b2764f38',
    ),
  );
  return $terms;
}
