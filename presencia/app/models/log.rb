class Log < ActiveRecord::Base
  belongs_to :equipo
  belongs_to :card
  belongs_to :usuario
end
