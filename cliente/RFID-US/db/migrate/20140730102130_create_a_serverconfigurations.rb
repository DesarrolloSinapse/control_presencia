class CreateAServerconfigurations < ActiveRecord::Migration
  def change
    create_table :a_serverconfigurations do |t|
      t.inet :ipdevice
      t.inet :networkmask
      t.inet :gateway
      t.text :url_server
      t.integer :refreshtime

      t.timestamps
    end
  end
end
