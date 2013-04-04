#!/usr/bin/macruby

require 'rubygems'
require 'chronic'

puts Chronic.parse "tomorrow in the evening"
puts Chronic.parse 'in a two days'
puts Chronic.parse 'a month ago'

