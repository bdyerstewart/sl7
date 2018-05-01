<?php
$output = "";
$output .= '<?xml version="1.0" encoding="utf-8" ?>';
$output .= '<rss version="2.0" xml:base="' . $link . '"' .  $namespaces;
$output .= '<channel>';
$output .= '<title>' . $title . '</title>';
$output .= '<link>' . $link . '</link>';
$output .= '<description>' . $description . '</description>';
$output .= '<language>' . $langcode . '</language>';
$output .= $channel_elements;
$output .= $items; 
$output .= '</channel>';
$output .= '</rss>';
print $output;
?>