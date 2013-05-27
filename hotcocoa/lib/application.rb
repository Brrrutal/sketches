begin
  framework 'CoreGraphics'
rescue
end
framework 'Cocoa'

require 'rubygems' # disable this for a deployed application
require 'hotcocoa'

class Hotcocoa
  include HotCocoa

  attr_accessor :main_view

  def start
    application name: 'Hotcocoa' do |app|
      app.delegate = self
      window frame: [100, 100, 500, 500], title: 'Hotcocoa' do |win|
        win << label(text: 'Hello from HotCocoa', layout: {start: false})
        win << main_view
        win.will_close { exit }
      end
    end
  end

  def create_main_view
    @main_view = view(:frame => [10, 10, 200, 240])
  end

  def main_view
    @main_view || create_main_view
  end

  # file/open
  def on_open(menu)
  end

  # file/new
  def on_new(menu)
    main_view << button(:title => "Test", :bezel => :regular_square, :frame => [10, 10, 100, 70])
  end

  # help menu item
  def on_help(menu)
  end

  # This is commented out, so the minimize menu item is disabled
  #def on_minimize(menu)
  #end

  # window/zoom
  def on_zoom(menu)
  end

  # window/bring_all_to_front
  def on_bring_all_to_front(menu)
  end
end

Hotcocoa.new.start
